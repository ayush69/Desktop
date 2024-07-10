const hexcodegen=function(){
    const hex="0123456789ABCDEF";
    hexcode="#";
    for(i=0;i<6;i++){
        hexcode+=hex[Math.floor(Math.random()*16)];
    }
    return hexcode;
}
let b=true;
const counter=function(){
    curr_count=0;
    while(i){
        curr_count+=1;
    }
    return curr_count;
}

let tobestopped;

const startchanging=function(){ 
   if(!tobestopped){
        tobestopped=setInterval(changebg,1000);
    };

    function changebg(){
        document.body.style.backgroundColor=hexcodegen();
        document.getElementById("counter").innerHTML=`<p>the hexcode of this bg is ${hexcodegen()}</p>`
    }
    
};
const stopchanging=function(){
    clearInterval(tobestopped);
    tobestopped=null;
};


document.querySelector('#start').addEventListener('click',startchanging,b=true);
stop_button=document.querySelector('#stop').addEventListener('click',stopchanging,b=false);
console.log(b);


