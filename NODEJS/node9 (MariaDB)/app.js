import mariadb from 'mariadb';

const conn = await mariadb.createConnection({
  host: '192.168.15.11',
  port: '3306',
  database: 'CT2HTML',
  user: 'root',
  password: '74123'
});

try {
  const res = await conn.query('SELECT * FROM client');
  console.log(res);
} 
finally {
  conn.end();
}