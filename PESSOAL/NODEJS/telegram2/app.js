import ConectorTelegram from './ConectorTelegram.js';

let bot = new ConectorTelegram();
bot.debugMode = 1;

bot.criarMenu("/menu", (msg, conversa) => {
    if (msg == "/start") {
        if (conversa["infos"]["usuario"] === undefined)
            bot.EnviarMensagem(conversa["id"],"Bem vindo ao menu Principal \nDigite \"login\" para comecar.");
        else 
            bot.EnviarMensagem(conversa["id"],"Bem vindo ao menu Principal, " + conversa["infos"]["usuario"]);
    }
    else if (msg == "login") {
        bot.RedirecionarMenu(conversa["id"], "/login");
        return;
    }
    else {
        bot.EnviarMensagem(conversa["id"], "Comando nao reconhecido: "+ msg);
    }
});

bot.criarMenu("/login", (msg, conversa) => {
    if (conversa["infos"]["usuario"] !== undefined) delete conversa["infos"]["usuario"];

    if (msg == "/start") {
        bot.EnviarMensagem(conversa["id"],"Digite seu nome de usuario:");
    } 
    else if (conversa["infos"]["usuario"] === undefined) {
        bot.EnviarMensagem(conversa["id"], "Bem vindo " + msg + ". \nDigite sua senha:");
        conversa["infos"]["usuario"] = msg;
    } 
    else {
        bot.EnviarMensagem(conversa["id"], "Senha -> "+ msg);
        if (conversa["infos"]["usuario"] == "lucas" && msg == "74123")
            bot.EnviarMensagem(conversa["id"], "Login correto");
        else {
            bot.EnviarMensagem(conversa["id"], "Login errado");
            delete conversa["infos"]["usuario"];
        }
        bot.RedirecionarMenu(conversa["id"], "/menu");
    }
});

bot.setMenuDefault("/menu");


// TELEAMIGO_BOT TOKEN
bot.start('1754600796:AAGxsM7AK3F3_o4ktRiGkMr0AXDn1UOBnAE');