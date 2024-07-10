import express from "express"
import userModel from "./modelprac.js"
import configs from "./configs.js"

import connectDb from "./dbconnect.js"

const app = express()

connectDb()
.then(()=>{
    app.listen(configs.port,()=>{
        console.log("server started at: ",configs.port)
    })
})
.catch((error)=>{
    console.log("error ",error)
})


app.get("/",(req,res)=>{
    res.send("hello again nodemon" )
})

