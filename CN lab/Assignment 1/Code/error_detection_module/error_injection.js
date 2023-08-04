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


module.exports.bypasscrc=function(codeword,generator){
    if(codeword.length>generator.length){
        return codeword;
    }
    let l=generator.length;
    for(let i=0;i<l;i++){
        let codeind=codeword.length-1-i;
        let generatorind=generator.length-1-i;
        if(generator.charAt(generatorind)=="1"){
            if(codeword.charAt(codeind)=="1"){
                codeword=codeword.replaceAt(codeind,"0");
            }
            else{
                codeword=codeword.replaceAt(codeind,"1");
            }
        }
    }
    return codeword;
}


module.exports.bypasschecksum=function(codeword_raw,word_len){
    let codeword=codeword_raw;
    // console.log("data word length ",dataword.length);
    while(codeword.length%word_len!=0){
        codeword='0'+codeword;
    }
    let wordList=[];//will contain the 16 bit words of the dataword 
    for(let i=0;i<(codeword.length/word_len);i++){
        wordList.push(codeword.substring(i*word_len,(i+1)*word_len));
    }
    let l=wordList.length;
    // let flag=false;
    for(let i=0;i<word_len;i++){
        let one=0;
        let zero=0;
        for(let j=1;j<l;j++){
            if(wordList[j].charAt(i)=="1"){
                one++;
            }
            else{
                zero++;
            }
        }
        if(zero>0&&one>0){
            let oneind=0;
            for(let j=1;j<l;j++){
                if(wordList[j].charAt(i)=="1"){
                    oneind=j;
                    break;
                }
            }
            let zeroind=0;
            for(let j=1;j<l;j++){
                if(wordList[j].charAt(i)=="0"){
                    zeroind=j;
                    break;
                }
            }
            wordList[oneind]=wordList[oneind].replaceAt(i,"0");
            wordList[zeroind]=wordList[zeroind].replaceAt(i,"1");
            break;
        }
    }
    let newCodeword="";
    for(let str of wordList){
        newCodeword=newCodeword+str;
    }
    return newCodeword.substring(newCodeword.length-codeword_raw.length);
}


//error injection module completed