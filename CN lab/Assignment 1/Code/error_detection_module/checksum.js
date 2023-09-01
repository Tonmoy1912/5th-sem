String.prototype.replaceAt = function(index, replacement) {
    return this.substring(0, index) + replacement + this.substring(index + replacement.length);
}

//return the checksum string of word_len length
module.exports.getChecksum= function getChecksum(wordList,word_len){
    let sum=0;
    let limit=(1<<word_len);
    for(i of wordList){
        sum+=parseInt(i,2);//convert a binary string into decimal
        if(sum>=limit){//convert to wrap sum
            sum=sum%limit+1;//convert a decimal into binary string
        }
    }
    sum=sum.toString(2);
    //make the length equal to word_len
    while(sum.length!=word_len){
        sum='0'+sum;
    }
    let checksum="";
    //1's complement to get the checksum
    for(let i=0;i<word_len;i++){
        if(sum.charAt(i)=="1"){
            checksum=checksum+"0";
        }
        else{
            checksum=checksum+"1";
        }
    }
    return checksum;
};


//return the codeword string
module.exports.getChecksumCodeWord= function getChecksumCodeWord(dataword_raw,word_len){
    //make the length multiple of word_len(in our case 16)
    let dataword=dataword_raw;
    // console.log("data word length ",dataword.length);
    while(dataword.length%word_len!=0){
        dataword='0'+dataword;
    }
    let wordList=[];//will contain the 16 bit words of the dataword 
    for(let i=0;i<(dataword.length/word_len);i++){
        wordList.push(dataword.substring(i*word_len,(i+1)*word_len));
    }
    
    let checksum=this.getChecksum(wordList,word_len);
    // console.log("binary check sum",checksum,"decimal checksum",parseInt(checksum,2));
    let checksum_codeword=dataword_raw+checksum;
    return checksum_codeword;
};

//return boolean
module.exports.isValidChecksum=function isValidChecksum(codeword_raw,word_len){
    let codeword=codeword_raw;
    // console.log("data word length ",codeword.length);
    while(codeword.length%word_len!=0){
        codeword='0'+codeword;
    }
    let wordList=[];//will contain the 16 bit words of the codeword
    for(let i=0;i<(codeword.length/word_len);i++){
        wordList.push(codeword.substring(i*word_len,(i+1)*word_len));
    }
    let checksum=this.getChecksum(wordList,word_len);
    // console.log("binary check sum",checksum,"decimal checksum",parseInt(checksum,2));
    return parseInt(checksum,2)==0;
};


// let checksum_codeword=this.getChecksumCodeWord("1111011110000000110",4);
// // checksum_codeword="1"+checksum_codeword;
// // checksum_codeword=checksum_codeword+"1";
// // checksum_codeword=checksum_codeword.replaceAt(5,"0");
// let isValid=this.isValidChecksum(checksum_codeword,4);
// if(isValid){
//     console.log("the code word is valid");
// }
// else{
//     console.log("the code word is not valid");
// }


// checksum module completed