import mongoose from "mongoose"

const userSchema = new mongoose.Schema({
    name:{
        type : String,
        required : true
    },
    userid:{
        type : String,
        required : true,
        unique : true
    },
    password:{
        type : String,
        required : true
    }

},{timestamps:true},{versionkey:false})

const user = mongoose.model("user",userSchema)

export default user