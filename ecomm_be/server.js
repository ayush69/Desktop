
import { Port } from './configs/server.config.js'
import { dburl } from "./configs/db.config.js"
import { connect } from "mongoose"
import express, { json } from 'express'
import userModel from "./models/user.model.js"
import { hashSync } from "bcrypt"

import route from "./routes/auth.route.js"

const App = express()

App.use(json())

route(App)

async function init(){

    try {
        let user = await userModel.findOne({userid:"admin"})

        if(user){
            console.log("admin is already present")
            return
        }
    } catch (err) {
        console.log("error happened",err)
    }

    try {
        
        user = await userModel.create({
            name : "ayush",
            userid : "admin",
            email : "ayush@gmail.com",
            usertype : "admin",
            number : 4123456789,
            password : hashSync("ayush123",8)
        })
        console.log("admin created",user)

    } catch (err) {
        console.log("error while creating the admin",err)
    }

}

const connectDb = async () => {
    try {
        const connectionInstance = await connect(dburl)
        console.log("connected to mongodb \n",connectionInstance.connection.host)
    } catch (error) {
        console.log("error while connecting to mongodb ",error)
    }
}



connectDb()
.then(
async ()=>{

App.listen(Port, ()=>{
    console.log("server started at port no. :", Port)
})

init()

})
.catch((error)=>{
    console.log("error ",error)
})


App.get("/", (req,res)=>{
    return res.send("hello from home");
 })




