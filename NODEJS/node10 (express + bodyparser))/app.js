import express from 'express';
import bodyParser from 'body-parser';

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.post('/', (req, res) => {
    console.log(req);
    res.send('OK');
});

app.listen(3000);