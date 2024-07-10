import { Schema, Types, model } from 'mongoose'


/**
 * name
 * userid
 * password
 * email
 * mobileNo.
 * userType
 */


const userSchema= new Schema({

    name:{
        type : String,
        
    },
    userid:{
        type : String,
        unique : true
    },
    password:{
        type : String,
       
    },
    email:{
        type : String,
        unique : true,
        lowercase : true,
        minLength : 10
    },
    number:{
        type : Number,
        length : 10,
        unique : true
    },
    usertype:{
        type : String,
        default : "costumer",
        enum : ["costumer","admin"]
    }


},{timestamps:true,versionKey:false})

export default model("User",userSchema)