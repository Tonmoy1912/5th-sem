const Checksum=require("./error_detection_module/checksum");
const CRC=require("./error_detection_module/crc");
const fs=require("fs");

const CRC8="111010101";
const CRC10="11000110011";
const CRC16="11000000000000101";
const CRC32="100000100110000010001110110110111";


const generator=CRC8;
const word_len_checksum=16;
// const burst_err_len=15;


let err_crc_single=fs.readFileSync("./errcrcsingle.txt",{ encoding: 'utf8', flag: 'r' });
let err_crc_isolated_double=fs.readFileSync("./errcrcisodouble.txt",{ encoding: 'utf8', flag: 'r' });
let err_crc_odd=fs.readFileSync("./errcrcodd.txt",{ encoding: 'utf8', flag: 'r' });
let err_crc_burst=fs.readFileSync("./errcrcburst.txt",{ encoding: 'utf8', flag: 'r' });
let codeword_raw_crc=fs.readFileSync("./crccodeword.txt",{ encoding: 'utf8', flag: 'r' });
//bypass crc error
let err_bypasscrc=fs.readFileSync("./crccodeword.txt",{ encoding: 'utf8', flag: 'r' });

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


let err_checksum_single=fs.readFileSync("./errchecksumsingle.txt",{ encoding: 'utf8', flag: 'r' });
let err_checksum_isolated_double=fs.readFileSync("./errchecksumisodouble.txt",{ encoding: 'utf8', flag: 'r' });
let err_checksum_odd=fs.readFileSync("./errchecksumodd.txt",{ encoding: 'utf8', flag: 'r' });
let err_checksum_burst=fs.readFileSync("./errchecksumburst.txt",{ encoding: 'utf8', flag: 'r' });
let codeword_raw_checksum=fs.readFileSync("./checksumcodeword.txt",{ encoding: 'utf8', flag: 'r' });
//error bypass checksum
let err_bypasschecksum=fs.readFileSync("./errbypasschecksum.txt",{ encoding: 'utf8', flag: 'r' });


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