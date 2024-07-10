import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import Card from './components/Card'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
     <h1 className='bg-green-800 text-black p-4 rounded-xl mb-4'>tailwind test</h1>
     <Card username="vscode" btnText="click me"/>
     <Card username="second"/>
    </>
  )
}

export default App
