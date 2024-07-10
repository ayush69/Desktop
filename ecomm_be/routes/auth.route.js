import { Router } from "express"
import { signup, signin } from "../controllers/auth.controller.js"


export default (App)=>{

    App.post("/ecomm/api/auth/signup", signup)

    App.post("/ecomm/api/auth/signin", signin)

}