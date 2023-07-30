const fs=require("fs");
const Checksum=require("./error_detection_module/checksum");
const CRC=require("./error_detection_module/crc");
const ErrorInjection=require("./error_detection_module/error_injection");



const generator="1011";
const word_len_checksum=16;
const burst_err_len=5;

// let argv=process.argv;
// if(argv.length<3){
//     console.log("You forget to enter the file name");
//     return ;
// }
// let filename=argv[2];

// const data = fs.readFileSync(filename,
//     { encoding: 'utf8', flag: 'r' });

const data = fs.readFileSync("./input.txt",{ encoding: 'utf8', flag: 'r' });

// console.log(data);

let codeword_raw_crc=CRC.getCRCCodeWord(data,generator);
let codeword_raw_checksum=Checksum.getChecksumCodeWord(data,word_len_checksum);

let err_crc_single=ErrorInjection.injectSingleError(codeword_raw_crc);
let err_crc_isolated_double=ErrorInjection.injectTwoIsolatedError(codeword_raw_crc);
let err_crc_odd=ErrorInjection.injectOddError(codeword_raw_crc);
let err_crc_burst=ErrorInjection.injectBurstError(codeword_raw_crc,burst_err_len);


fs.writeFileSync("./errcrcsingle.txt",err_crc_single);
fs.writeFileSync("./errcrcisodouble.txt",err_crc_isolated_double);
fs.writeFileSync("./errcrcodd.txt",err_crc_odd);
fs.writeFileSync("./errcrcburst.txt",err_crc_burst);
fs.writeFileSync("./crccodeword.txt",codeword_raw_crc);


let err_checksum_single=ErrorInjection.injectSingleError(codeword_raw_checksum);
let err_checksum_isolated_double=ErrorInjection.injectTwoIsolatedError(codeword_raw_checksum);
let err_checksum_odd=ErrorInjection.injectOddError(codeword_raw_checksum);
let err_checksum_burst=ErrorInjection.injectBurstError(codeword_raw_checksum,burst_err_len);


fs.writeFileSync("./errchecksumsingle.txt",err_checksum_single);
fs.writeFileSync("./errchecksumisodouble.txt",err_checksum_isolated_double);
fs.writeFileSync("./errchecksumodd.txt",err_checksum_odd);
fs.writeFileSync("./errchecksumburst.txt",err_checksum_burst);
fs.writeFileSync("./checksumcodeword.txt",codeword_raw_checksum);