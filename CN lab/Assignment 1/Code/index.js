const express=require("express");
const Checksum=require("./error_detection_module/checksum");
const CRC=require("./error_detection_module/crc");


const port=8000;

const app=express();

app.use(express.json());

function crchandler(req,res){
    let {codeword_raw_crc,err_crc_single,err_crc_isolated_double,err_crc_odd,err_crc_burst,generator} =req.body;
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
}

app.post("/checkcrc",crchandler);

app.listen(port,function(err){
    if(err){
        console.error(err.message);
    }
    else{
        console.log(`The server is running on port ${port}`)
    }
});