import TelegramBot from 'node-telegram-bot-api';

class ConectorTelegram {
    debugMode = 0;
    Menus = {};
    
    criarMenu(comando_menu, funcao_do_menu) {
        // funcao_do_menu(infos, msg);
        this.Menus[comando_menu] = funcao_do_menu;
    }

    setMenuDefault(menu) {
        this.menuDefault = menu;
    }

    Conversas = [];
    pegarConversa(id) {
        for (let i = 0; i < this.Conversas.length; i++)
            if (this.Conversas[i]["id"] == id) return this.Conversas[i];
        return null;
    }

    bot;
    EnviarMensagem(ChatId, msg) {
        this.bot.sendMessage(ChatId, msg);
    }

    RedirecionarMenu(ChatId, menu) {
        for (let i = 0; i < this.Conversas.length; i++) {
            if (this.Conversas[i]["id"] == ChatId) {
                this.Conversas[i]["infos"]["menu"] = menu;
                this.Menus[this.Conversas[i]["infos"]["menu"]]("/start", this.Conversas[i]);
                console.log("TG_BOT-> " + this.Conversas[i]["id"] + " :: redirecionado para menu: " + menu);
            } 
        }
    }

    start (use_token) {
        const token = use_token;
        this.bot = new TelegramBot(token, {polling: true});

        this.bot.on("polling_error", console.log);

        this.bot.on('message', (msg) => {
            const ChatId = msg.chat.id;
            let conversa = this.pegarConversa(ChatId);
            if (conversa == null) {
                conversa = {
                    id: ChatId,
                    infos: {
                        menu: this.menuDefault,
                    }
                };

                if (this.debugMode) console.log("TG_BOT-> " + ChatId + " :: ADICIONADA NOVA CONVERSA AO SISTEMA");
                this.Conversas.push(conversa);
                console.log(this.Conversas);
            }
            
            this.Menus[conversa["infos"]["menu"]](msg.text, conversa);
        });
    }
};

export default ConectorTelegram;