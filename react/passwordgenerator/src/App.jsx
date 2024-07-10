import { useCallback, useEffect, useRef, useState } from 'react'

import './App.css'





function App() {
  const [length, setlength]=useState(8);
  const [numallowed,setnumallowed]=useState(false);
  const [charallowed,setcharallowed]=useState(false);
  const [password,setpassword]=useState("");
  
const passwordgenerator = useCallback(()=>{
  let pass="";
  let str="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  if(numallowed) str+="0123456789"

  if(charallowed) str+="!@#$%&*"

  for (let i= 0; i<length; i++) {
    let rand=Math.floor(Math.random()*str.length+1)
    pass+=str.charAt(rand)
  }

setpassword(pass)
},[length,numallowed,charallowed])

const copyytoclip = useCallback(()=>{
  window.navigator.clipboard.writeText(password)
  passref?.current.select();
  passref?.current.setSelectionRange(0,51)
},[password])

useEffect(passwordgenerator,[length,numallowed,charallowed])

const passref = useRef(null)

  return (
    <>
    <div>
    <h1 className='text-xl text-center text-white'>Password Generator</h1>
    <div>
      <input type="text" 
       value={password}
       readOnly
       ref={passref}
      />
      <button className='text-white'
       onClick={copyytoclip}
      >copy</button>
    </div>
    

    <div>
      <input type='range'
       min={6}
       max={50}
       value={length} 
       onChange={(e)=>{setlength(e.target.value)}}
      />
      <label className='text-white'>Length:{length}  </label>
      <input type="checkbox"
       value={numallowed}
       onChange={()=>{setnumallowed(prev=>!prev)}}
      />
      <label className='text-white'>Numbers </label>
      <input type="checkbox"
       value={charallowed}
       onChange={()=>{setcharallowed(prev=>!prev)}}
      />
      <label className='text-white'>Characters </label>

    </div>
    
    </div>
    </>
  )
}

export default App
