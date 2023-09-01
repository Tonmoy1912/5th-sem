// import logo from './logo.svg';
// import './App.css';

// import { useState } from 'react';s
import './App.css';
import { io } from "socket.io-client";
import { eventWrapper } from '@testing-library/user-event/dist/utils';
import Stop_and_Wait from './component/stop_and_wait';

// const generator=CRC8;
const word_len_checksum=16;
// const burst_err_len=15;
// const socket = io.connect("http://localhost:8000");
// socket.on("connect", function () {
//   console.log("Conneted to the socket server");
// });




function App() {

  const socket = io.connect("http://localhost:8000");
  socket.on("connect", function () {
    console.log("Conneted to the socket server");
  });

  socket.on("err",function(data){
    console.log(data.message);
  })

  return (
    <>
      <h1>Flow Control Mechanisms for Data Link Layer</h1>
      <Stop_and_Wait socket={socket} word_len_checksum={word_len_checksum} />
    </>
  );
}

export default App;
