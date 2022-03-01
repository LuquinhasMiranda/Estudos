require('./logger');

const EventEmitter = require('events');
const emitter = new EventEmitter();

emitter.emit('logger', {message:'teste de mensagem logger'});