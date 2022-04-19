import TelegramBot from 'node-telegram-bot-api';

const token = '1754600796:AAGxsM7AK3F3_o4ktRiGkMr0AXDn1UOBnAE';
//@teleamigo_bot

const bot = new TelegramBot(token, {polling: true});

bot.onText(/\/echo (.+)/, (msg, match) => {

  const chatId = msg.chat.id;
  const resp = match[1];

  bot.sendMessage(chatId, resp);
});

bot.on('message', (msg) => {
  const chatId = msg.chat.id;

  console.log(msg);

  bot.sendMessage(chatId, 'Received your message');
});