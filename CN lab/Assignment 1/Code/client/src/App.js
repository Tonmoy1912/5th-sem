
import { useState } from 'react';
import './App.css';
import {io} from "socket.io-client";
import { eventWrapper } from '@testing-library/user-event/dist/utils';

// const crc=require("./../../error_detection_module/crc");
// const crc=require("./error_detection_module/crc");
const Checksum=require("./error_detection_module/checksum");
const CRC=require("./error_detection_module/crc");
const ErrorInjection=require("./error_detection_module/error_injection");

const CRC8="111010101";
const CRC10="11000110011";
const CRC16="11000000000000101";
const CRC32="100000100110000010001110110110111";


// const generator=CRC8;
// const word_len_checksum=16;
// const burst_err_len=15;



function App() {
  const socket=io.connect("http://localhost:8000");
  socket.on("connect",function(){
    console.log("Conneted to the socket server");
  });


  const [crcScheme,setCrcScheme]=useState("");
  const [burstLen,setBurstLen]=useState("");
  const [wordLen,setWordLen]=useState("");
  const [dataword,setDataword]=useState("");


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


  const handleSend=function(){
    let generator=crcScheme.toUpperCase();
    generator=`${eval(generator)}`;
    const word_len_checksum=parseInt(wordLen);
    const burst_err_len=parseInt(burstLen);
    // console.log(generator);

    let codeword_raw_crc=CRC.getCRCCodeWord(dataword,generator);
    let codeword_raw_checksum=Checksum.getChecksumCodeWord(dataword,word_len_checksum);

    let err_crc_single=ErrorInjection.injectSingleError(codeword_raw_crc);
    let err_crc_isolated_double=ErrorInjection.injectTwoIsolatedError(codeword_raw_crc);
    let err_crc_odd=ErrorInjection.injectOddError(codeword_raw_crc);
    let err_crc_burst=ErrorInjection.injectBurstError(codeword_raw_crc,burst_err_len);
    //bypass crc error
    let err_bypasscrc=ErrorInjection.bypasscrc(codeword_raw_crc,generator);


    console.log("code word CRC:");
    console.log(codeword_raw_crc);
    console.log("bypass error for CRC:");
    console.log(err_bypasscrc);

 

    let err_checksum_single=ErrorInjection.injectSingleError(codeword_raw_checksum);
    let err_checksum_isolated_double=ErrorInjection.injectTwoIsolatedError(codeword_raw_checksum);
    let err_checksum_odd=ErrorInjection.injectOddError(codeword_raw_checksum);
    let err_checksum_burst=ErrorInjection.injectBurstError(codeword_raw_checksum,burst_err_len);
    //bypass checksum error
    let err_bypasschecksum=ErrorInjection.bypasschecksum(codeword_raw_checksum,word_len_checksum);

    console.log("code word Chechsum:");
    console.log(codeword_raw_checksum);
    console.log("bypass error for Checksum:");
    console.log(err_bypasschecksum);
   


    socket.emit("data_send",{
      codeword_raw_crc,
      codeword_raw_checksum,
      err_crc_single,
      err_crc_isolated_double,
      err_crc_odd,
      err_crc_burst,
      err_bypasscrc,
      err_checksum_single,
      err_checksum_isolated_double,
      err_checksum_odd,
      err_checksum_burst,
      err_bypasschecksum,
      generator,
      word_len_checksum,
      burst_err_len
    });
    console.log("data send");
  }


  const handleCrcChange=function(event){
    setCrcScheme(event.target.value);
  }

  const handleWordLenChange=function(event){
    setWordLen(event.target.value);
  }

  const handleBurstLenChange=function(event){
    setBurstLen(event.target.value);
  }

  return (
    <div className="App">
      <h1>Checksum and Cyclic Redundancy Check</h1>
      <input type="file" onChange={handleFileChange}/>
      <br />
      
      <label htmlFor="crcscheme">CRC Scheme</label>
      <input type="text" value={crcScheme} id="crcscheme" onChange={handleCrcChange}/>
      <br />
      <label htmlFor="wordLen">Word length for Checksum</label>
      <input type="text" value={wordLen} id="wordLen" onChange={handleWordLenChange}/>
      <br />
      <label htmlFor="burstLen">Burst Error Length</label>
      <input type="text" value={burstLen} id="burstLen" onChange={handleBurstLenChange}/>
      <br />
      <button onClick={handleSend}>Send</button>
    </div>
  );
}

export default App;
