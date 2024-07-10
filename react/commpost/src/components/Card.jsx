import React from 'react'
import Btn from './Btn'
import './Card.css'

function Card({
  LogoImg,
  ChannelName,
  Description,
  PostImg
}) {
  return (
    <div className="card-container">
        
    <div className="channelinfo">
    <div className='logo'>
        <img src={LogoImg} alt="logo" className='logo-img' />
    </div>
    <div className='channel-name'>
        {ChannelName}
    </div>
    <div className='subscribe'>
        <button className='sub-btn'>subscribe</button>
    </div>
    </div>

  <div className="description">{Description}</div>

  <div className="photo">
    <img src={PostImg} alt="post-img" className='post-img'/>
  </div>

  <div className="reactions">
    
    <div className="leftreactions">
      <button className='like'>like</button>
      <button className='dislike'>dislike</button>
    </div>

    <div className="rightreactions">
      <button className='share'>share</button>
      <button className='comment'>comment</button>
    </div>
  

  </div>

</div>
  )
}

export default Card