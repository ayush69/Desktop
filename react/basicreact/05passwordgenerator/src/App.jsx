import { useState ,useCallback,useEffect,useRef} from 'react'

function App() {
  const [length, setLength] = useState(8)
  const [includeNumber,setincludeNumber]=useState(false)
  const [includeCharacters,setincludeCharacters]=useState(false)
  const [password,setpassword]=useState("")

const passwordRef = useRef(null)

  const passwordgenerator = useCallback( ()=>{
    let pass=""
    let string="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

    if(includeNumber) string+="0123456789"
    if(includeCharacters) string+="!@#$%^&*()"

    for(let i=1;i<=length;i++){
      let char=Math.floor(Math.random()*string.length+1)
      pass+=string.charAt(char)
    }
    setpassword(pass)

  }
    ,[length,includeCharacters,includeNumber,setpassword])
  
const copypasswordtoclipboard = useCallback(()=>{
  passwordRef.current?.select();
  passwordRef.current?.setSelectionRange(0,77);
  window.navigator.clipboard.writeText(password)
 
},[password])


useEffect( ()=>{passwordgenerator()},[length,includeCharacters,includeNumber,passwordgenerator])
  return (
    <>
      <div className='w-full max-w-md mx-auto shadow-md rounded-lg px-4 my-8 text-orange-500 bg-gray-800 '>
        <h1 className='text-white text-center'>password generator</h1>
        <div className='flex shadow rounded-lg overflow-hiddden mb-4'>
           <input type="text"
           value={password} 
           className='outline-none h-full w-full py-1 px-3 my-2'
           placeholder='password'
           readOnly
           ref={passwordRef}
           />
           <button
           onClick={copypasswordtoclipboard} 
           className='outline-none rounded-lg bg-blue-700 text-white px-2 py-0.5 shrink-0'
           >copy</button>
        </div>
         <div className='flex text-sm gap-x-2'>
          <div className='flex items-center gap-x-1'>
            <input type="range"
            min={6}
            max={25}
            value={length}
            className='cursor-pointer'
            onChange={(e)=>{setLength(e.target.value)}}
            
            />
            <label>length:{length}</label>
          </div>
          <div className='flex items-cneter gap-x-1'>
            <input type="checkbox"
            defaultChecked={includeNumber}
            id='numberinput'
            onChange={()=>{setincludeNumber((prev)=>!prev)}} />
            <label htmlFor="numberinput">numbers</label>

          </div>
          <div className='flex items-cneter gap-x-1'>
            <input type="checkbox"
            defaultChecked={includeCharacters}
            id='numberinput'
            onChange={()=>{setincludeCharacters((prev)=>!prev)}} />
            <label htmlFor="charinput">characters</label>

          </div>
         </div>
      </div>

    </>
  )
}

export default App
