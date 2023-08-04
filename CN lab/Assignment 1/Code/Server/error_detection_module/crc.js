String.prototype.replaceAt = function(index, replacement) {
    return this.substring(0, index) + replacement + this.substring(index + replacement.length);
}

// return the codeword string
module.exports.getCRCCodeWord= function(dataword_raw,generator){
    let dataword=dataword_raw;
    //creating augmented data word
    for(let i=0;i<generator.length-1;i++){
        dataword=dataword+"0";
    }
    //created augmented polynomial
    let polyarr=new Array(dataword.length);
    polyarr.fill(0);
    let l=dataword.length-1;
    for(let i=0;i<=l;i++){
        if(dataword.charAt(l-i)=="1"){
            polyarr[i]=1;
        }
    }
    let g=generator.length-1;// g is the degree of the polynomial as well as the length of the remainder
    //creating generator polynomial
    let garr=new Array();
    for(let i=0;i<=g;i++){
        if(generator.charAt(g-i)=="1"){
            garr.push(i);
        }
    }
    //calculating the remainder
    for(let i=l;i>=g;i--){
        if(polyarr[i]==1){
            let x=i-g;
            for(let ele of garr){
                polyarr[ele+x]=polyarr[ele+x]^1;
            }
        }
    }
    //getting the binary string remainder
    let remainder="";
    for(let i=0;i<g;i++){
        if(polyarr[i]==1){
            remainder="1"+remainder;
        }
        else{
            remainder="0"+remainder;
        }
    }
    let codeword=dataword_raw+remainder;
    return codeword;
};


//return boolean
module.exports.isValidCRC= function(codeword_raw,generator){
    let dataword=codeword_raw;
    //creating polynomial of codeword
    let polyarr=new Array(dataword.length);
    polyarr.fill(0);
    let l=dataword.length-1;
    for(let i=0;i<=l;i++){
        if(dataword.charAt(l-i)=="1"){
            polyarr[i]=1;
        }
    }
    let g=generator.length-1;// g is the degree of the polynomial as well as the length of the remainder
    //creating generator polynomial
    let garr=new Array();
    for(let i=0;i<=g;i++){
        if(generator.charAt(g-i)=="1"){
            garr.push(i);
        }
    }
    //calculating the remainder
    for(let i=l;i>=g;i--){
        if(polyarr[i]==1){
            let x=i-g;
            for(let ele of garr){
                polyarr[ele+x]=polyarr[ele+x]^1;
            }
        }
    }
    //getting the binary string remainder
    let remainder="";
    for(let i=0;i<g;i++){
        if(polyarr[i]==1){
            remainder="1"+remainder;
        }
        else{
            remainder="0"+remainder;
        }
    }
    // let codeword=dataword_raw+remainder;
    // return codeword;
    // console.log(remainder);
    return parseInt(remainder,2)==0;
};


// let arr=new Array(10);
// arr.fill(0);
// arr[3]=arr[3]^1;
// arr[3]=arr[3]^1;
// console.log(arr);

// let codeword=this.getCRCCodeWord("1001","1011");
// console.log(codeword);
// // codeword=codeword.replaceAt(3,"0");
// // this.isValidCRC(codeword,"1011");
// if(this.isValidCRC(codeword,"1011")){
//     console.log("valid");
// }
// else{
//     console.log(("error"));
// }


//crc module completed