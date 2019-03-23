
"use strict";

let AnalogWrite = require('./AnalogWrite.js')
let ServoWrite = require('./ServoWrite.js')
let AnalogRead = require('./AnalogRead.js')
let DigitalRead = require('./DigitalRead.js')
let ServoRead = require('./ServoRead.js')
let DigitalWrite = require('./DigitalWrite.js')
let DigitalSetDirection = require('./DigitalSetDirection.js')

module.exports = {
  AnalogWrite: AnalogWrite,
  ServoWrite: ServoWrite,
  AnalogRead: AnalogRead,
  DigitalRead: DigitalRead,
  ServoRead: ServoRead,
  DigitalWrite: DigitalWrite,
  DigitalSetDirection: DigitalSetDirection,
};
