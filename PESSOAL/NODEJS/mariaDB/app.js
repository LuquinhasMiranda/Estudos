import mariadb from 'mariadb';

const conn = await mariadb.createConnection({
  host: 'localhost',
  port: '3306',
  //database: 'CT2HTML',
  user: 'root',
  password: '000000'
});

try {
  const res = await conn.query('SELECT * FROM client');
  console.log(res);
} 
finally {
  conn.end();
}