import React,{useState} from 'react'


const checksumScheme=require("../error_detection_module/checksum");
const errorInjection=require("../error_detection_module/error_injection");

let frames=[];
let injectError=[];
let eventId=[];
let ackList=[];
let curFrame=0;
let startTime,endTime;

export default function Stop_and_Wait(props) {

  const {socket,word_len_checksum}=props;

  // let times=1;

  function randomIntFromInterval(min, max) { // min and max included 
    return Math.floor(Math.random() * (max - min + 1) + min)
  }


  // socket.emit("data_send","Data is send from stop and wait");
  const [dataword,setDataword]=useState("");
  const [err_pro,setErrPro]=useState("0");
  const [payload_size,setPayloadSize]=useState("46");
  const [timeout,setTimeout]=useState("0.5");


  // let frames=[];
  // let injectError=[];
  // let eventId=[];
  // let ackList=[];
  // let curFrame=0;
  // let startTime,endTime;

  function Framing(){
    let payload=dataword;
    //padding
    let payloadSize=eval(payload_size);
    while(payload.length%payloadSize!=0){
      payload="0"+payload;
    }
    //break into frames
    for(let i=0;i<(payload.length/payloadSize);i++){
      // wordList.push(payload.substring(i*payloadSize,(i+1)*payloadSize));
      let temp=payload.substring(i*payloadSize,(i+1)*payloadSize);
      let frame={
        header:{
          source:" EC-2E-98-77-20-AD",
          destination:" EC-2E-98-77-20-AD",
          length:payloadSize,
          seq_no:i
        },
        data:temp,
        trailer:checksumScheme.getChecksumCodeWord(temp,word_len_checksum)//return the checksum
      };
      frames.push(frame);
    }
  }

  function channel(){
    let n=frames.length;
    injectError=new Array(n);
    injectError.fill(0);
    let t=Math.floor(n*eval(err_pro));
    for(let i=0;i<t;i++){
      let j=randomIntFromInterval(0,n-1);
      // while(injectError[j]!=0){
      //   j=(j+1)%n;
      // }
      injectError[j]++;
    }
    // console.log(injectError);
    console.log(`inject Error`,injectError);
  }

  function send(){
    // let n=frames.length;
    // eventId=new Array(n);
    // ackList=new Array(n);
    // eventId.fill(null);
    // ackList.fill(0);
    // startTime=Date.time();
    // socket.emit("data_send_SAW",)
    console.log(frames);
    console.log(ackList);
    console.log(eventId);
    console.log(`curFrame ${curFrame}`);
    if(curFrame>=frames.length){

      return ;
    }
    if(injectError[curFrame]>0){
      console.log(`error inject called for frame ${curFrame}`);
      injectError[curFrame]--;
      let frame=frames[curFrame];
      // frame.data=errorInjection.injectSingleError(frame.data);
      frame={
        header:frame.header,
        data:frame.data.substring(0),
        trailer:frame.trailer//return the checksum
      };
      socket.emit("data_send_SAW",{frame,word_len_checksum});
    }
    else{
      let frame=frames[curFrame];
      // frame.data=errorInjection.injectSingleError(frame.data);
      socket.emit("data_send_SAW",{frame,word_len_checksum});
      let codeword=frame.data+frame.trailer;
      if(checksumScheme.isValidChecksum(codeword,word_len_checksum)){
        console.log(`Code word is valid for frame ${curFrame}`);
      }
      else{
        console.log(`Code word is not valid for frame ${curFrame}`);
      }
    }
    console.log(`frame ${curFrame} transmitted`);
    let i=curFrame;
    // console.log(`timeout ${timeout}`);

    eventId[i]=setTimeout(function(){
      TimeOut(i);
    },1000);

    curFrame++;//
  }

  function TimeOut(i){
    if(ackList[i]==1){
      return ;
    }
    //ack not received yet
    if(injectError[i]>0){
      injectError[i]--;
      let frame=frames[i];
      // frame.data=errorInjection.injectSingleError(frame.data);
      frame={
        header:frame.header,
        data:frame.data.substring(0),
        trailer:frame.trailer//return the checksum
      };
      socket.emit("data_send_SAW",{frame,word_len_checksum});
    }
    else{
      let frame=frames[i];
      // frame.data=errorInjection.injectSingleError(frame.data);
      socket.emit("data_send_SAW",{frame,word_len_checksum});
    }
    console.log(`frame ${i} re-transmitted`);
    eventId[i]=setTimeout(function(){
      TimeOut(i);
    },1000);
  }

  function Recv(data){
    clearTimeout(eventId[data]);
    ackList[data]=1;
    console.log(`Ack for frame ${data} received`);
    send();
  }

  socket.on("data_ack_SAW",function(data){
    // console.log(times);
    // times++;
    Recv(data);
    if(data==frames.length-1){
      endTime=Date.now();
      let totalTime=(endTime-startTime)/1000;
      console.log(`Time taken to complete the data transfer ${totalTime}`);
    }
  });


  const handleFileChange=function(event){
    const file=event.target.files[0];
    const reader=new FileReader();
    reader.readAsText(file);
    reader.onload=function(){
      // console.log("file data:\n",reader.result,"Type : ",typeof reader.result)
      // const crcCodeword=crc.getCRCCodeWord(reader.result,"10110001010101010010001101");
      // console.log("code word",crcCodeword);
      setDataword(reader.result);
    };
    reader.onerror=function(){
      console.log("Error on reading the file",reader.error);
    }
  }

  const handleErrProChange=function(event){
    setErrPro(event.target.value);
  }

  const handlePayloadSizeChange=function(event){
    setPayloadSize(event.target.value);
  }

  const handleTimeoutChange=function(event){
    setTimeout(event.target.value);
  }

  const handleSend=function(event){
    // socket.emit("data_send",dataword);
    // console.log(dataword);
    // let i=eval(err_pro)+2;
    // console.log(i,typeof i);
    // console.log('times');
    frames=[];
    injectError=[];
    eventId=[];
    ackList=[];
    curFrame=0;
    Framing();
    channel();
    let n=frames.length;
    eventId=new Array(n);
    ackList=new Array(n);
    eventId.fill(null);
    ackList.fill(0);
    startTime=Date.now();
    send();//send the frames using socket
  }

  return (
    <div>
      <h1>Stop and Wait</h1>
      {/* <h1>Checksum and Cyclic Redundancy Check</h1> */}
      <input type="file" onChange={handleFileChange}/>
      <br />
      
      <label htmlFor="err_pro">The Probability of error</label>
      <input type="text" value={err_pro} id="err_pro" onChange={handleErrProChange}/>
      <br />
      <label htmlFor="payloadSize">Payload Size</label>
      <input type="text" value={payload_size} id="payloadSize" onChange={handlePayloadSizeChange}/>
      <br />
      <label htmlFor="timeout">Time out</label>
      <input type="text" value={timeout} id="timeout" onChange={handleTimeoutChange}/>
      <br />
      <button onClick={handleSend}>Send</button>
    </div>
  )
}
