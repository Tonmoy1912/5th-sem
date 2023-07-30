String.prototype.replaceAt = function(index, replacement) {
    return this.substring(0, index) + replacement + this.substring(index + replacement.length);
}


function randomIntFromInterval(min, max) { // min and max included 
    return Math.floor(Math.random() * (max - min + 1) + min)
}
  
module.exports.injectSingleError=function(codeword_raw){
    let len=codeword_raw.length;
    let randomIndex=randomIntFromInterval(0,len-1);
    if(codeword_raw.charAt(randomIndex)=="1"){
        return codeword_raw.replaceAt(randomIndex,"0");
    }
    else{
        return codeword_raw.replaceAt(randomIndex,"1");
    }
};


module.exports.injectTwoIsolatedError=function(codeword_raw){
    let len=codeword_raw.length;
    let randomIndex=randomIntFromInterval(0,len-1);
    if(codeword_raw.charAt(randomIndex)=="1"){
        codeword_raw=codeword_raw.replaceAt(randomIndex,"0");
    }
    else{
        codeword_raw=codeword_raw.replaceAt(randomIndex,"1");
    }
    let ranInd=randomIntFromInterval(2,len-2);
    randomIndex=(randomIndex+ranInd)%len;
    if(codeword_raw.charAt(randomIndex)=="1"){
        codeword_raw=codeword_raw.replaceAt(randomIndex,"0");
    }
    else{
        codeword_raw=codeword_raw.replaceAt(randomIndex,"1");
    }
    return codeword_raw;
}

module.exports.injectOddError=function(codeword_raw){
    let len=codeword_raw.length;
    let no=randomIntFromInterval(0,len);
    if(no%2==0){
        no=(no+1)%len;
    }
    let mark=new Array(len);
    mark.fill(0);
    let count=0;

    while(count<no){
        let randomIndex=randomIntFromInterval(0,len-1);
        if(mark[randomIndex]==0){
            mark[randomIndex]=1;
            count++;
            if(codeword_raw.charAt(randomIndex)=="1"){
                codeword_raw=codeword_raw.replaceAt(randomIndex,"0");
            }
            else{
                codeword_raw=codeword_raw.replaceAt(randomIndex,"1");
            }
        }
    }
    return codeword_raw;
};

module.exports.injectBurstError=function(codeword_raw,error_len){
    if(error_len==0){
        return codeword_raw;
    }
    let len=codeword_raw.length;
    error_len=Math.min(len,error_len);
    let randomIndex=randomIntFromInterval(0,len-error_len);
    let newError="";
    for(let i=0;i<error_len;i++){
        if(codeword_raw.charAt(i+randomIndex)=="1"){
            codeword_raw=codeword_raw.replaceAt(i+randomIndex,"0");
        }
        else{
            codeword_raw=codeword_raw.replaceAt(i+randomIndex,"1");
        }
    }
    return codeword_raw;
};


//error injection module completed