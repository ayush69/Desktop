import mongoose from "mongoose"
import configs from "./configs.js"

const connectDb = async () => {
    try {
        const connectionInstance = await mongoose.connect(configs.db_url)
        console.log("connected to mongodb \n",connectionInstance.connection.host)
    } catch (error) {
        console.log("error while connecting to mongodb ",error)
    }
}

export default connectDb