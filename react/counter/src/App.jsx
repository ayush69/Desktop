import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  
let [counter,setCounter]=useState(6)

//let counter=6

const addValue=()=>{
  console.log("clicked",Math.random(),counter);  
  //counter=counter+1
  setCounter(counter+1)
  if (counter>19){
    setCounter(20);
  }
}
const decValue=()=>{
  console.log("decreased");
  setCounter(counter-1)
  if (counter<1){
    setCounter(0);
  }
  
}
  return (
    <>
     <h1>chai aur react</h1>
     <h2>counter value: {counter}</h2>

     <button
     onClick={addValue}
     >add value</button>
     <br />
     <button
     onClick={decValue}
     >decrease value</button>
    
    </>
  )
}

export default App
