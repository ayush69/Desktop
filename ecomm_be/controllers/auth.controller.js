import userModel from "../models/user.model.js"
import { hashSync, compareSync } from "bcrypt"

export async function signup(req,res){

    const requestbody = req.body

    const userObj = {
        name : requestbody.name,
        userid : requestbody.userid,
        password : hashSync(requestbody.password,8),
        email : requestbody.email,
        number : requestbody.number,
        usertype : requestbody.usertype
        
    }


    try {
        
        const userCreated = await userModel.create({userObj})

        const resultuser = {
            name : userCreated.name,
            userid : userCreated.userid,
            email : userCreated.email,
            number : userCreated.number,
            usertype : userCreated.usertype,
            createdAt : userCreated.createdAt,
            updatedAt : userCreated.updatedAt
        }

        res.status(201).send(resultuser)

    } catch (err) {
        console.log("error during registering",err)
        res.status(500).send({
            message : "error during registering"
        })
        
    }
}


export async function signin(req,res){

    const userexists = await userModel.find({userid : req.body.userid})

    if(userexists==null){
        console.log("user do not exist")
        res.status(401).send({
            message:"user do not exist"
        })

    }

    const isPasswordValid = compareSync(req.body.password, userexists.password)
    if(!isPasswordValid){
        return res.status(401).send({
            message : "invalid password"
        })
    }



    res.status(200).send({
        name : userexists.name,
        userid :userexists.userid,
        email : userexists.email,
        number : userexists.number,
        usertype : userexists.usertype
    })


    


}