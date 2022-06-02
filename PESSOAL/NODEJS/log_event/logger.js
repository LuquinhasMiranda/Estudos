const EventEmitter = require('events');
const emitter = new EventEmitter();

const timer = require('timers');

emitter.on('logger', (err, args) => {
    console.log('[log]: ', args['message'])
});