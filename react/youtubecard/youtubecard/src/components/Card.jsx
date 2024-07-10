import React from 'react'
import Btn from "./Btn"


function card() {
  return (
    <>
        
    <div className="channelinfo">
    <div>
        <img src="" alt="logo" />
    </div>
    <div>
        Channel Name
    </div>
    <div>
        <button>subscribe</button>
    </div>
    </div>

  <div className="description">this is the description</div>

  <div className="photo">
    <img src="" alt="" />
  </div>

  <div className="reactions">
    
    
    <Btn action_name="like"/>
    <Btn action_name="dislike"/> 
    <Btn action_name="share"/>
    <Btn action_name="comment"/>
    

  </div>

</>
  )
}

export default card