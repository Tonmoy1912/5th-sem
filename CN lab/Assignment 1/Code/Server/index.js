const express=require("express");
const http=require("http");
const {Server}=require("socket.io");
const cors=require("cors");
const { Socket } = require("engine.io");

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



const app=express();
app.use(cors());
const server=http.createServer(app);
const io=new Server(server,{
    cors:{
        origin:"http://localhost:3000",
        methods:["GET","POST"]
    }
});

io.on("connection",function(socket){
    console.log("User connected with socket id :",socket.id);
    socket.on("data_send",function(data){
        const {
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
          }=data;

          console.log("\n\ngenerator",generator);
          console.log("Word length for checksum",word_len_checksum);
          console.log("Burst error length",burst_err_len);
          console.log("\n");
          console.log("Output for CRC:");

          if(CRC.isValidCRC(codeword_raw_crc,generator)){
              console.log("Raw codeword found valid");
          }
          else{
              console.log("Raw codeword found non-valid");
          }
          
          
          if(CRC.isValidCRC(err_crc_single,generator)){
              console.log("Single error found valid");
          }
          else{
              console.log("Single error found non-valid");
          }
          
          if(CRC.isValidCRC(err_crc_isolated_double,generator)){
              console.log("Isolated double error found valid");
          }
          else{
              console.log("Isolated double error found non-valid");
          }
          
          if(CRC.isValidCRC(err_crc_odd,generator)){
              console.log("Odd err found valid");
          }
          else{
              console.log("Odd err found non-valid");
          }
          
          if(CRC.isValidCRC(err_crc_burst,generator)){
              console.log("Burst error found valid");
          }
          else{
              console.log("Burst error found non-valid");
          }
          
          if(CRC.isValidCRC(err_bypasscrc,generator)){
              console.log("Bypass error found valid");
          } 
          else{
              console.log("Bypass error found non-valid");
          }
          
          console.log("\n\nOutput for Checksum");

          if(Checksum.isValidChecksum(codeword_raw_checksum,word_len_checksum)){
            console.log("Raw codeword found valid");
        }
        else{
            console.log("Raw codeword found non-valid");
        }
        
        
        if(Checksum.isValidChecksum(err_checksum_single,word_len_checksum)){
            console.log("Single error found valid");
        }
        else{
            console.log("Single error found non-valid");
        }
        
        if(Checksum.isValidChecksum(err_checksum_isolated_double,word_len_checksum)){
            console.log("Isolated double error found valid");
        }
        else{
            console.log("Isolated double error found non-valid");
        }
        
        if(Checksum.isValidChecksum(err_checksum_odd,word_len_checksum)){
            console.log("Odd err found valid");
        }
        else{
            console.log("Odd err found non-valid");
        }
        
        if(Checksum.isValidChecksum(err_checksum_burst,word_len_checksum)){
            console.log("Burst error found valid");
        }
        else{
            console.log("Burst error found non-valid");
        }
        
        if(Checksum.isValidChecksum(err_bypasschecksum,word_len_checksum)){
            console.log("Bypass error found valid");
        }
        else{
            console.log("Bypass error found non-valid");
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