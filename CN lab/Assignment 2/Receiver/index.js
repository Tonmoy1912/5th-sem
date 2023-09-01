const express=require("express");
const http=require("http");
const {Server}=require("socket.io");
const cors=require("cors");
const { Socket } = require("engine.io");
const checksumScheme=require("./error_detection_module/checksum");



// const generator=CRC8;
// const word_len_checksum=16;
// const burst_err_len=15;



const app=express();
app.use(cors());
const server=http.createServer(app);
const io=new Server(server,{
    cors:{
        origin:"http://localhost:3000",
        methods:["GET","POST"]
    }
});

const connectionsLimit=2;

io.on("connection",function(socket){



    if (io.engine.clientsCount > connectionsLimit) {
        socket.emit('err', { message: 'reach the limit of connections' })
        socket.disconnect()
        console.log('Disconnected...')
        return
    }



    console.log("User connected with socket id :",socket.id);


    //for stop and wait protocol
    socket.on("data_send_SAW",function(data){
    //    console.log(data);
    //     socket.emit("data_ack",null);
        let {frame,word_len_checksum}=data;
        if(frame==undefined){
            return ;
        }
        console.log(frame.data,frame.trailer,word_len_checksum);
        let codeword=frame.data+frame.trailer;
        if(checksumScheme.isValidChecksum(codeword,word_len_checksum)){
            socket.emit("data_ack_SAW",frame.header.seq_no);
            console.log(`Socket: ${socket.id}, frame ${frame.header.seq_no} received`);
        }
        else{
            console.log(`Socket: ${socket.id}, frame ${frame.header.seq_no} is corrupted`);
        }
    });

});


server.listen(8000,function(err){
    if(err){
        console.log("Error on running the server",err.message);
    }
    else{
        console.log("Server is running on port 8000");
    }
})