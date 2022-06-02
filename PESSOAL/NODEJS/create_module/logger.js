var url = 'http://mylogger.io/log';
function log(message) {
    // SEND HTTP REQUEST
    console.log('logger: ' + message);
    console.log(__filename);
    console.log(__dirname);
}

module.exports = log;