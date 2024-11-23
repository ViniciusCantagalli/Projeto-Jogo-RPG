#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definição do registro para os personagens
struct Personagem {
    string nome;
    float vida;
    float ataque;
    float defesa;
    int velocidade;
    string habilidade1;
    string habilidade2;
    string caracteristica;
};

// Função para exibir o menu e escolher o personagem
int escolherPersonagem(Personagem personagens[], int numPersonagens) {
    cout << "Escolha qual personagem voce vai querer jogar:" << endl;
    for (int i = 0; i < numPersonagens; i++) {
        cout << i + 1 << ". " << personagens[i].nome << endl;
    }
    int escolha;
    cout << "Digite o numero do personagem: ";
    cin >> escolha;
    return escolha - 1; // Retorna o índice do personagem escolhido
}

// Função para exibir as informações do personagem escolhido
void exibirInformacoesPersonagem(const Personagem& personagem) {
	cout << "\n---------------------------------------" << endl;
    cout << "Voce escolheu: " << personagem.nome << endl;
    cout << "Vida: " << personagem.vida << endl;
    cout << "Ataque: " << personagem.ataque << endl;
    cout << "Defesa: " << personagem.defesa << endl;
    cout << "Velocidade: " << personagem.velocidade << endl;
    cout << "Habilidade 1: " << personagem.habilidade1 << endl;
    cout << "Habilidade 2: " << personagem.habilidade2 << endl;
    cout << "Caracteristicas: " << personagem.caracteristica << endl;
    cout << "----------------------------------------" << endl;
}

// Função para salvar o progresso do jogo
void salvarProgresso(const Personagem& personagem, const string& filename) {
    ofstream arquivo(filename);
    if (arquivo.is_open()) {
        arquivo << personagem.nome << endl;
        arquivo << personagem.vida << endl;
        arquivo << personagem.ataque << endl;
        arquivo << personagem.defesa << endl;
        arquivo << personagem.velocidade << endl;
        arquivo.close();
        cout << "\nProgresso salvo com sucesso!" << endl;
    } else {
        cout << "\nErro ao salvar o progresso." << endl;
    }
}

// Função para carregar o progresso do jogo
void carregarProgresso(Personagem& personagem, const string& filename) {
    ifstream arquivo(filename);
    if (arquivo.is_open()) {
        getline(arquivo, personagem.nome);
        arquivo >> personagem.vida;
        arquivo >> personagem.ataque;
        arquivo >> personagem.defesa;
        arquivo >> personagem.velocidade;
        arquivo.close();
        cout << "\nProgresso carregado com sucesso!" << endl;
    } else {
        cout << "\nErro ao carregar o progresso." << endl;
    }
}

// Função para a cena inicial com Senhor Jorge
void cenaInicial(Personagem& personagemEscolhido) {
    cout << "\nVoce chega a uma pequena aldeia e eh recebido por um cavaleiro velho e sabio chamado Senhor Jorge." << endl;
    cout << "Senhor Jorge: Ah, jovem aventureiro! Finalmente, alguem disposto a ouvir! O reino esta em grande perigo." << endl;
    cout << "O rei foi atacado por forcas malignas e sua saude esta se deteriorando rapidamente.\nSomente um heroi destemido pode ajuda-lo a recuperar o que foi perdido.\n" << endl;

    cout << "Escolha sua resposta:" << endl;
    cout << "1. Estou pronto para ajudar! O que devo fazer?" << endl;
    cout << "2. E se eu nao puder? Nao sei se sou forte o suficiente." << endl;
    cout << "3. O que exatamente aconteceu com o rei?" << endl;

    int resposta;
    cout << "\nDigite o numero da sua resposta: ";
    cin >> resposta;

    // Respostaa
    switch (resposta) {
        case 1:
        	cout << "\n--------------------------------------------" << endl;
            cout << "\nSenhor Jorge: Otimo! Sua coragem eh admiravel!" << endl;
            break;
        case 2:
        	cout << "\n--------------------------------------------" << endl;
            cout << "\nSenhor Jorge: Todos comecam de algum lugar. A coragem eh o que importa!" << endl;
            break;
        case 3:
        	cout << "\n--------------------------------------------" << endl;
            cout << "\nSenhor Jorge: O rei foi atacado por criaturas sombrias que ameacam nosso reino. Precisamos de voce!" << endl;
            break;
        default:
        	cout << "\n--------------------------------------------" << endl;
            cout << "\nResposta invalida." << endl;
            break;
    }

    cout << "\nSenhor Jorge: Nao importa qual caminho voce escolher, o primeiro passo e se preparar." << endl;
    cout << "Escolha um dos tres cenarios: a Floresta Negra, o Castelo Amaldicoado ou a Montanha dos Gigantes." << endl;
    cout << "Cada um deles tem seus proprios desafios, mas a coragem e a determinacao o levarao aonde voce precisa ir.\n" << endl;

    cout << "Escolha seu cenario:" << endl;
    cout << "1. Floresta Negra" << endl;
    cout << "2. Castelo Amaldicoado" << endl;
    cout << "3. Montanha dos Gigantes" << endl;

    int cenaEscolhida;
    cout << "\nDigite o numero do cenario: ";
    cin >> cenaEscolhida;
    void florestaNegra(Personagem& personagemEscolhido);
    void casteloAmaldicoado(Personagem& personagemEscolhido);
    void montanhaDosGigantes(Personagem& personagemEscolhido);

    switch (cenaEscolhida) {
        case 1:
        	cout << "\n-------------------------------------------------" << endl;
            cout << "\nVoce decidiu ir para a Floresta Negra. Prepare-se para os desafios que o aguardam!" << endl;
            florestaNegra(personagemEscolhido);
            break;
        case 2:
        	cout << "\n-------------------------------------------------" << endl;
            cout << "\nVoce decidiu ir para o Castelo Amaldicoado. Prepare-se para os desafios que o aguardam!" << endl;
            casteloAmaldicoado(personagemEscolhido);
            break;
        case 3:
        	cout << "\n-------------------------------------------------" << endl;
            cout << "\nVoce decidiu ir para a Montanha dos Gigantes. Prepare-se para os desafios que o aguardam!" << endl;
            montanhaDosGigantes(personagemEscolhido);
            break;
        default:
        	cout << "\n-------------------------------------------------" << endl;
            cout << "\nCenario invalido. A aventura nao pode comecar." << endl;
            break;
    }
}

// Função para a Floresta Negra
void florestaNegra(Personagem& personagemEscolhido) {
   cout << "\nA Floresta Negra eh um lugar antigo e envolto em misterios, com arvores imponentes que parecem sussurrar" << endl;
   cout << "segredos. A vegetacao eh densa, formando um labirinto natural onde a luz do sol luta para atravessar a copa das arvores." << endl;
   cout << "Reza a lenda que o local foi amaldicoado seculos atras, quando um druida, exilado de sua vila, lancou um feitico de" << endl;
   cout << "vinganca. Desde entao, espiritos e criaturas sombrias vagam pela floresta, fazendo com que muitos" << endl;
   cout << "que entram nela jamais retornem." << endl;

   cout << "\nAo longo do caminho, o cavaleiro sente uma presenca" << endl;
   cout << "constante, como se fosse observado de perto. O vento" << endl;
   cout << "frio carrega vozes e sussurros, que confundem a" << endl;
   cout << "direcao e aumentam o sentimento de perigo iminente." << endl;
   cout << "O objetivo eh encontrar o Amuleto do Crepusculo, uma" << endl; 
   cout << "reliquia lendaria que dizem estar escondida na" << endl;
   cout << "Floresta Negra e que concede uma grande habilidade ao" << endl;
   cout << "seu portador." << endl;

	// Encontro com a Sombra da Floresta
   cout << "\nVoce esta andando pela floresta, e de repente comeca a sentir uma " << endl;
   cout << "sensacao estranha. Alguns minutos depois caminhando por essa floresta," << endl;
   cout << "voce encontra uma criatura, a Sombra da Floresta. Um espirito ancestral" << endl;
   cout << "moldado pelas sombras das arvores." << endl;

   cout << "Ele desliza silenciosamente entre as copas e aparece de repente," << endl;
   cout << "atacando com uma velocidade sobrenatural. A Sombra da Floresta cria" << endl;
   cout << "ilusoes e sombras vivas, confundindo o cavaleiro e testando sua" << endl;
   cout << "percepcao. Ela sussurra em um tom ameacador e tenta jogar com os" << endl;
   cout << "medos mais profundos do heroi." << endl;

   cout << "Ele comeca a te atacar em uma velocidade sobrenatural.\n" << endl;



    // Batalha contra a Sombra da Floresta
int vidaChefe = 18;

while (true) { 
    while (vidaChefe > 0 && personagemEscolhido.vida > 0) {
        cout << "Escolha sua acao:" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Defender" << endl;

        int acao;
        cout << "\nDigite o numero da sua acao: ";
        cin >> acao;

        switch (acao) {
            case 1:
                vidaChefe -= personagemEscolhido.ataque;
                cout << "\n-----------------------------------------" << endl;
                cout << "Voce ataca a Sombra da Floresta e causa " << personagemEscolhido.ataque << " de dano." << endl;
                break;
            case 2:
            	cout << "\n-----------------------------------------" << endl;
                cout << "Voce se defende e recebe 1 de dano." << endl;
                break;
            default:
            	cout << "\n-----------------------------------------" << endl;
                cout << "Acao invalida." << endl;
                break;
        }

        if (vidaChefe > 0) {
            if (acao != 2) {
                personagemEscolhido.vida -= 2;
                cout << "A Sombra da Floresta ataca voce e causa 2 de dano." << endl;
            }
            else {
                personagemEscolhido.vida -= 1;
                cout << "A Sombra da Floresta ataca voce, mas voce se defende e recebe apenas 1 de dano." << endl;
            }
        }

        cout << "\nVida do chefe: " << vidaChefe << endl;
        cout << "Vida do jogador: " <<personagemEscolhido.vida << endl;
        cout << "-----------------------------------------" << endl;
    }

    if (vidaChefe <= 0) {
        cout << "Voce acabou de derrotar a Sombra da Floresta!\nAgora voce pode continuar sua jornada normalmente." << endl;
        salvarProgresso(personagemEscolhido, "progresso.txt"); 
        cout << "-----------------------------------------" << endl;
        break; 
    } else {
        cout << "Voce foi derrotado pela Sombra da Floresta." << endl;
        
        vidaChefe = 18;
        personagemEscolhido.vida = 10;
        cout << "Voce retorna ao checkpoint e pode enfrentar o chefe novamente." << endl;
        cout << "-----------------------------------------" << endl;
    }
}

   	// Interação com a Velha Feiticeira
  	cout << "De repente, enquanto esta continuando seu caminho, voce encontra uma " << endl;
    cout << "mulher parada sozinha em meio a tanta escuridao e imensidao dessa " << endl;
   	cout << "floresta, a Velha Feiticeira." << endl;
   	cout << "Mas voce fica em duvida se ela pode ser confiavel, afinal, ela esta " << endl;
    cout << "parada parecendo estar esperando alguma coisa, e voce acabou de sair de " << endl;
   	cout << "uma batalha dificil." << endl;
   	cout << "Porem, mesmo assim voce da uma chance para ela. Voce chega nela para " << endl;
   	cout << "conversar..." << endl;
   	cout << "Velha Feiticeira: Cuidado por onde anda meu jovem! Esta floresta eh " << endl;
   	cout <<  "perigosa, e o guardiao das raizes esta protegendo ela\n" << endl;

  	cout << "1. Perguntar sobre quem eh o Guardiao das Raizes." << endl;
  	cout << "2. Agradecer e seguir seu caminho.\n" << endl;


    int interacao;
    cout << "Digite o numero da sua escolha: ";
    cin >> interacao;

    if (interacao == 1) {
    	cout << "\n-------------------------------------------------" << endl;
        cout << "\nVoce: Quem eh o Guardiao das Raizes?" << endl;
        cout << "Velha Feiticeira: O Guardiao das Raizes eh uma criatura poderosa que protege o coracao da floresta." << endl;
        cout << "Ele eh feito de galhos e raizes grossas e possui uma forca esmagadora." << endl;
    } else if (interacao == 2) {
    	cout << "\n-------------------------------------------------" << endl;
        cout << "\nVoce: Obrigado, vou seguir meu caminho." << endl;
        cout << "Velha Feiticeira : Que a sorte esteja com voce, jovem aventureiro." << endl;
    }
    cout << "\nA Velha Feiticeira mora la por muito tempo, e adverte o cavaleiro sobre todos os perigos e armadilhas sobre a floresta.\n" << endl;

    // Coleta de iten
    cout << "\n-------------------------------------------------" << endl;
    cout << "\nVoce encontra um bau escondido entre alguns tr oncos caidos pelo chao, dentro dele possui itens raros." << endl;
  	cout << "Voce abre e ve que dentro do bau ha um arco enfeiticado e uma armadura mais forte." << endl;
  	cout << "O arco enfeiticado aumenta seu ataque em 1, mas voce so pode pega-lo se souber manusear um arco." << endl;
  	cout << "A armadura mais forte aumentara sua vida para 12 na batalha contra o Guardiao das Raizes.\n" << endl;


    int escolhaArco, escolhaArmadura;
    bool pegouArco = false;
    bool pegouArmadura = false;
    

    // Pergunta sobre o arco
    cout << "Digite 1 para pegar o arco enfeiticado ou 2 para nao pegar: ";
    cin >> escolhaArco;

    if (escolhaArco == 1) {
        // Verifica se o personagem sabe manusear um arco
        if (personagemEscolhido.habilidade1 == "Tiro Certeiro") { 
            pegouArco = true;
            cout << "\n----------------------------------------------" << endl;
            cout << "Voce pegou o arco enfeiticado! Seu ataque aumentou em 1 ponto." << endl;
            cout << "----------------------------------------------" << endl;
            personagemEscolhido.ataque += 1; 
        } 
		else {
			cout << "\n----------------------------------------------" << endl;
            cout << "Voce nao sabe manusear um arco, somente Arthur pode pegar este item." << endl;
            cout << "----------------------------------------------" << endl;
        }
    } 
		else {
			cout << "\n----------------------------------------------" << endl;
        	cout << "Voce nao pegou o arco enfeiticado." << endl;
        	cout << "----------------------------------------------" << endl;
    	}
		
    // Pergunta sobre a armadura
    cout << "\nDigite 1 para pegar a armadura mais forte ou 2 para nao pegar: ";
    cin >> escolhaArmadura;

    if (escolhaArmadura == 1) {
        pegouArmadura = true;
        cout << "\n----------------------------------------------" << endl;
        cout << "\nVoce pegou a armadura mais forte! Sua vida aumentara para 12 na batalha contra o Guardiao das Raizes." << endl;
        cout << "----------------------------------------------" << endl;
    } else {
    	cout << "\n----------------------------------------------" << endl;
        cout << "Voce nao pegou a armadura mais forte." << endl;
        cout << "----------------------------------------------" << endl;
    }

    // Aumentando a vida se pegar a armadura
    if (pegouArmadura) {
        personagemEscolhido.vida = 12; 
    }


    // Encontro com o Guardião das Raízes
   	cout << "Enquanto voce ainda esta se recuperando da sua ultima batalha, e ainda "  << endl;
    cout << "pensando o que era aquilo que voce acabou de enfrentar, voce comeca a "  << endl;
    cout << "perceber que as arvores em sua volta estao se mexendo demais, seus galhos "  << endl;
    cout << "estao balancando e voce nao sentiu nenhum vento forte para isso estar "  << endl;
    cout << "acontecendo." << endl;
	  cout << "\nEntao, voce comeca a ficar mais atento ao seu redor, e percebe que as "  << endl;
    cout << "coisas estao ficando estranhas. Mesmo sendo um guerreiro, voce comeca a "  << endl;
    cout << "ficar com um pouco de medo com o ambiente se tornando cada vez mais sombrio." << endl;
	  cout << "Voce decide dar uma pausa na sua jornada para descansar, entao, voce senta "  << endl;
    cout << "em um tronco caido no meio da floresta. No mesmo instante em que voce se "  << endl;
    cout << "senta, o chao comeca a tremer como um terremoto, e as arvores comecam a "  << endl; 
    cout << "balancar cada vez mais. Os corvos que estavam nas arvores comecam a voar e "  << endl;
    cout << "formam uma especie de furacao no ceu." << endl;
	  cout << "De repente, enquanto voce fica assustado e se levanta para correr, uma "  << endl;
    cout << "criatura bizarrada comeca a se levantar de dentro do solo, essa criatura e "  << endl;
    cout << "gigante!" << endl;
	  cout << "\nVoce esta proximo ao coracao da floresta, e essa criatura e o Guardiao das "  << endl;
    cout << "Raizes, ele esta la para proteger a qualquer custo a floresta." << endl;
	  cout << "Ele emerge do solo como uma gigantesca criatura feita de galhos e raizes "  << endl;
    cout << "grossas. Ele possui uma forca esmagadora e e capaz de prender o cavaleiro "  << endl;
    cout << "com suas raizes. Sua presenca e acompanhada pelo som de madeira se partindo, "  << endl;
    cout << "e ele exala um aroma de podridao. O cavaleiro deve encontrar uma maneira de "  << endl;
    cout << "enfraquece-lo antes que ele se torne imbativel." << endl;

	vidaChefe = 22;  
while (true){
    while (vidaChefe > 0 && personagemEscolhido.vida > 0) {
        cout << "\nEscolha sua acao:" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Defender" << endl;

        int acao;
        cout << "\nDigite o numero da sua acao: ";
        cin >> acao;

        switch (acao) {
            case 1:
                vidaChefe -= personagemEscolhido.ataque;
                cout << "\n-----------------------------------------" << endl;
                cout << "Voce ataca o Guardiao das Raizes e causa " << personagemEscolhido.ataque << " de dano." << endl;
                break;
            case 2:
            	cout << "\n-----------------------------------------" << endl;
                cout << "Voce se defende e recebe 1 de dano." << endl;
                break;
            default:
            	cout << "\n-----------------------------------------" << endl;
                cout << "Acao invalida." << endl;
                break;
        }

        if (vidaChefe > 0) {
            if (acao != 2) {
                personagemEscolhido.vida -= 2;
                cout << "\nO Guardiao das Raizes ataca voce e causa 2 de dano." << endl;
            }
            else {
            	personagemEscolhido.vida -= 1;
                cout << "\nO Guardiao das Raizes ataca voce, mas voce se defende e recebe apenas 1 de dano." << endl;
			}
        }

        cout << "\nVida do chefe: " << vidaChefe << endl;
        cout << "Vida do jogador: " << personagemEscolhido.vida << endl;
        cout << "-----------------------------------------" << endl;
	}

	    if (vidaChefe <= 0) {
	        cout << "\nVoce derrotou o Guardiao das Raizes!\nMas agora voce acabou ficando muito ferido, foi uma batalha muito intensa.\nMas mesmo assim voce decide continuar a sua jornada e ajudar o rei." << endl;
	        salvarProgresso(personagemEscolhido, "progresso.txt"); 
	        cout << "\n-----------------------------------------" << endl;
	        break;
	    } else {
	        cout << "\nVoce foi derrotado pelo Guardiao das Raizes." << endl;
	        vidaChefe = 22;
	        personagemEscolhido.vida = 10;
	        cout << "Voce retorna ao checkpoint e pode enfrentar o chefe novamente." << endl;
	        cout << "-----------------------------------------" << endl;
	    }
	
}
	    // Encontro com Clara
	    cout << "\nEnquanto voce esta seguindo o caminho, voce encontra uma elfa " << endl;
	    cout << "chamada Clara. Ela eh uma guia que conhece bem os caminhos do " << endl;
	    cout << "reino e aparece com uma expressao aliviada ao ver que voce " << endl;
	    cout << "sobreviveu." << endl;
		  cout << "Voce nao deve permanecer aqui por muito mais tempo. Posso " << endl;
	    cout << "guia-lo de volta ao reino, mas sera um caminho repleto de " << endl;
	    cout << "desafios. Voce esta pronto?" << endl;
	    cout << "\n----------------------------------------------------" << endl;


        int escolhaClara;
        cout << "1. Sim, estou pronto para ir!" << endl;
        cout << "2. Por que voce vive aqui, Clara?" << endl;
        cout << "3. E se houver mais monstros pelo caminho? Posso enfrenta-los?" << endl;
        cout << "4. Nao quero sua ajuda. Posso encontrar o caminho sozinho.\n" << endl;
        cout << "Digite o numero da sua escolha: ";

        cin >> escolhaClara;

        switch (escolhaClara) {
            case 1:
            	cout << "\n----------------------------------------------------" << endl;
                cout << "\nOtimo! Sigam-me, mas esteja atento. Ha espiritos inquietos que ainda vagam por aqui. Mantenha seu amuleto proximo; ele pode protege-lo." << endl;
                break;
            case 2:
            	cout << "\n----------------------------------------------------" << endl;
                cout << "\nA Floresta Negra tem suas sombras, mas tambem tem suas belezas. Eu protejo o equilibrio da natureza. Com o seu amuleto, voce pode trazer luz a esse lugar. Vamos." << endl;
                break;
            case 3:
            	cout << "\n----------------------------------------------------" << endl;
                cout << "\nSeus desafios nao terminaram, mas voce eh forte. O Amuleto do Crepusculo lhe dara uma vantagem. Confie em suas habilidades e siga-me. Juntos, podemos superar qualquer obstaculo." << endl;
                break;
            case 4:
            	cout << "\n----------------------------------------------------" << endl;
                cout << "\nSe e isso que deseja, saiba que a floresta pode ser traicoe ira. Muitas vezes, a solidao leva a perdicao. Mas se voce estiver determinado, siga o caminho do rio e mantenha-se atento. O destino eh seu, e sua escolha sera seu guia." << endl;
                break;
            default:
            	cout << "\n----------------------------------------------------" << endl;
                cout << "\nEscolha invalida." << endl;
                break;
        }

    	// Caminho de volta ao reino
    	cout << "\n----------------------------------------------------" << endl;
		  cout << "Voce continua seguindo o caminho de volta ao reino, com ou sem a ajuda "  << endl;
      cout << "de Clara. O caminho e longo e cheio de desafios, mas voce esta determinado "  << endl;
      cout << "a ajudar o rei." << endl;
  		cout << "Depois de horas de caminhada, voce finalmente chega ao reino. O rei o "  << endl;
  		cout << "recebe com gratidao e lhe agradece por ter trazido o Amuleto do Crepusculo."  << endl;
  		cout << "O rei lhe diz que o amuleto e a chave para derrotar o mal que ameaca o "  << endl;
  		cout << "reino e que voce e o unico que pode ajuda-lo a salvar o reino." << endl;	
  		cout << "Voce aceita o desafio e se prepara para enfrentar o mal que ameaca o "  << endl;
  		cout << "reino." << endl;
		
		// Encontro com o Rei
		cout << "\n----------------------------------------------------" << endl;
		cout << "Depois de horas de caminhada, voce finalmente chega ao castelo. O " << endl;
		cout << "ambiente e sombrio e silencioso, pois rumores sobre a saude debilitada " << endl;
		cout << "do rei se espalharam pelo reino. Voce e levado imediatamente aos " << endl;
		cout << "aposentos reais, onde o rei, deitado em uma cama, respira com dificuldade" << endl;
		cout << "Rei: Meu bravo cavaleiro... fico feliz que tenha retornado. Ouvi sobre " << endl;
		cout << "sua coragem ao enfrentar as criaturas da floresta. Eu... estou muito fraco. " << endl;
		cout << "Preciso de sua ajuda para obter a erva sagrada que se encontra no Bosque " << endl;
		cout << "das Almas.\n" << endl;


		cout << "1. Aceitar imediatamente a missao." << endl;
		cout << "2. Perguntar ao rei mais sobre a erva sagrada." << endl;
		cout << "3. Perguntar se ele nao tem outra forma de se curar." << endl;

		int escolhaRei;
		cout << "Digite o numero da sua escolha: ";
		cin >> escolhaRei;

		if (escolhaRei == 1) {
			cout << "\n----------------------------------------------------" << endl;
   		 	cout << "\nVoce: Meu rei, nao se preocupe. Partirei agora mesmo para buscar a erva sagrada!" << endl;
    	 	cout << "Rei: Obrigado, meu nobre cavaleiro. Que os deuses estejam ao seu lado." << endl;
		} else if (escolhaRei == 2) {
			cout << "\n----------------------------------------------------" << endl;
    		cout << "\nVoce: O que exatamente e essa erva sagrada, meu rei?" << endl;
    		cout << "Rei: E uma planta rara que dizem ter o poder de restaurar a vitalidade. Cresce somente onde a luz e a sombra se encontram." << endl;
		} else if (escolhaRei == 3) {
			cout << "\n----------------------------------------------------" << endl;
    		cout << "\nVoce: Meu rei, nao ha outra maneira de cura?" << endl;
    		cout << "Rei: Infelizmente, esta e minha unica esperanca. A erva sagrada tem o poder que nenhuma outra poçao ou remedio possui." << endl;
}
		//Final
		  cout << "\nVoce parte em direcao ao Bosque das Almas. Depois de enfrentar varios " << endl;
      cout << "desafios, voce finalmente encontra a erva e retorna ao castelo." << endl;
  		cout << "De volta ao lado do rei, voce entrega a erva para os alquimistas reais, " << endl;
  		cout << "que rapidamente preparam uma pocao para ele beber." << endl;
  		cout << "\nAlguns momentos depois, o rei comeca a recuperar as cores e a forca. " << endl;
  		cout << "Ele se levanta e lhe sorri, agradecido." << endl;		
  		cout << "Rei: Voce salvou minha vida, bravo cavaleiro. Por seu heroismo e " << endl;
  		cout << "dedicacao, voce sera eternamente lembrado como o guardiao do reino." << endl;		
  		cout << "\nE assim, voce recebe o reconhecimento do rei e do povo. Seu nome e " << endl;
  		cout << "celebrado em todo o reino como o salvador do monarca e o heroi da Floresta " << endl;
  		cout << "Negra." << endl;
}

// Função para o Castelo Amaldicoado
void casteloAmaldicoado(Personagem& personagemEscolhido) {
    cout << "\nO Castelo Amaldicoado eh um lugar sombrio e intimidador, onde os "<< endl;
  	cout << "ecos de passos e correntes reverberam nos corredores vazios. O castelo " << endl;
   	cout <<	"foi governado por uma rainha que, em sua busca por poder absoluto, " << endl;
  	cout << "formou uma alianca sombria com um dragao, oferecendo-lhe abrigo em suas " << endl;
  	cout << "masmorras em troca de protecao. Eventualmente, a magia e as forcas " << endl;
  	cout << "sombrias se voltaram contra ela, transformando-a em um esprito aprisionado " << endl;
  	cout << "dentro das paredes do castelo." << endl;
  	cout << "\nNo interior, o cavaleiro encontra saloes repletos de armaduras vazias que " << endl;
  	cout << "parecem observar cada passo, e corredores escuros que se estendem como " << endl;
  	cout << "labirintos. Ao longe, um som profundo, semelhante ao de uma respiracao, " << endl;
   	cout << "ecoa nas profundezas do castelo, alertando sobre a presenca do dragao.\n" << endl;


    // Encontro com o Fantasma da Biblioteca do Castelo
    cout << "Voce vai adentrando pelo castelo e olhando por toda a sua volta. O " << endl;
    cout << "castelo eh gigante e bem escuro, mas voce nao fica com medo e continua " << endl;
    cout << "explorando, quando de repente..." << endl;
  	cout << "Voce encontra um fantasma que parece ser da biblioteca, ele esta " << endl;
  	cout << "sentado em uma mesa, cercado de livros antigos." << endl;
  	cout << "Fantasma da Biblioteca: Ah, um aventureiro! Eu posso ajudar voce a " << endl;
  	cout << "encontrar o que voce procura. Mas primeiro, voce precisa me ajudar a " << endl;
  	cout << "encontrar um livro que foi roubado por um ladrao.\n" << endl;
  	cout << "1. Sim, eu vou ajudar." << endl;
  	cout << "2. Nao, eu nao tenho tempo." << endl;

	int escolhaFantasma;
	cout << "Digite o numero da sua escolha: ";
	cin >> escolhaFantasma;
	
	if (escolhaFantasma == 1) {
		personagemEscolhido.ataque += 0.5;
		cout << "\n----------------------------------------------------" << endl;
	    cout << "\nFantasma da Biblioteca: Obrigado, aventureiro! O livro que foi " << endl;
  		cout << "roubado eh muito importante para mim. Ele contem informacoes sobre " << endl;
  		cout << "o dragao que vive no castelo. Se voce encontrar o livro, eu posso " << endl;
  		cout << "ajudar voce a derrotar o dragao." << endl;
  		cout << "Voce encontra o livro em uma sala escura do castelo, mas ao pegar o " << endl;
  		cout << "livro, voce ouve um barulho e o ladrao aparece." << endl;
  		cout << "Ladrao: Ah, voce achou o livro! Agora ele eh meu!" << endl;
  		cout << "Voce luta contra o ladrao e o derrota." << endl;
  		
  		cout << "\n----------------------------------------------------" << endl;
  		cout << "Fantasma da Biblioteca: Obrigado, aventureiro! Agora que voce tem o " << endl;
  		cout << "livro, eu posso ajudar voce a derrotar o dragao. O dragao tem um " << endl;
  		cout << "ponto fraco, ele eh vulneravel a ataques magicos." << endl;
	
	
	    cout << "\nFantasma da Biblioteca: Agora que voce derrotou o ladrao, como posso ajudar voce?" << endl;
	    cout << "1. Me conte mais sobre o dragao." << endl;
	    cout << "2. Preciso de mais informacoes sobre o Cavaleiro Espectral." << endl;
	    cout << "3. Nao preciso de ajuda no momento." << endl;
	
	    int escolhaAjuda;
	    cout << "Digite o numero da sua escolha: ";
	    cin >> escolhaAjuda;
	
	    switch (escolhaAjuda) {
	        case 1:
	        	cout << "\n----------------------------------------------------" << endl;
	            cout << "\nFantasma da Biblioteca: O dragao eh uma criatura astuta e poderosa." << endl;
	            cout << "Ele eh vulneravel a ataques magicos, entao use isso a seu favor!" << endl;
	            break;
	        case 2:
	        	cout << "\n----------------------------------------------------" << endl;
	            cout << "\nFantasma da Biblioteca: O Cavaleiro Espectral eh um guardiao do castelo." << endl;
	            cout << "Ele eh rapido e forte, mas tem um ponto fraco: ataques rapidos o desestabilizam." << endl;
	            break;
	        case 3:
	        	cout << "\n----------------------------------------------------" << endl;
	            cout << "\nFantasma da Biblioteca: Entendo, aventureiro. Se precisar de ajuda no futuro, estarei aqui." << endl;
	            break;
	        default:
	        	cout << "\n----------------------------------------------------" << endl;
	            cout << "\nEscolha invalida." << endl;
	            break;
	    }
	} else {
	    cout << "\nFantasma da Biblioteca: Entendo, aventureiro. Mas lembre-se, o dragao eh muito perigoso.\nSe voce nao tiver cuidado, ele pode matar voce." << endl;
	}

    // Encontro com o Sábio Maluco
   	cout << "\n----------------------------------------------------" << endl;
  	cout << "\nApos passar pelo Fantasma, voce comeca a achar a situacao esquisita, " << endl;
  	cout << "e ve que realmente aquele castelo nao eh normal." << endl;
  	cout << "Voce comeca a entrar em uma especie de tunel com varias tochas pelas " << endl;
  	cout << "paredes. Quando olha pra tras, todas as tochas atras de voce se apagam, " << endl;
  	cout << "entao voce continua seguindo caminho. Quando de repente..." << endl;
  	cout << "\nVoce encontra um homem acorrentado em uma masmorra, ele parece ser um homem sabio e velho" << endl;
  	cout << "Sabio Maluco: Ah, um aventureiro! Eu posso ajudar voce a derrotar " << endl;
  	cout << "o dragao. Mas primeiro, voce precisa me ajudar a escapar daqui." << endl;

    cout << "\nVoce aceita ajudar o sabio?" << endl;
    cout << "1. Sim, eu vou ajudar." << endl;
    cout << "2. Nao, eu nao tenho tempo." << endl;

    int escolhaSabio;
    cout << "Digite o numero da sua escolha: ";
    cin >> escolhaSabio;
    

    if (escolhaSabio == 1) {
    	personagemEscolhido.ataque += 0.5;
    	cout << "\n----------------------------------------------------" << endl;
        cout << "\nSabio Maluco: Obrigado, aventureiro! Agora que voce me ajudou a escapar, eu posso ajudar voce a derrotar o dragao." << endl;
        cout << "O dragao tem um ponto fraco, ele eh vulneravel a ataques magicos.\nAlem disso, o Cavaleiro Espectral que guarda o salao principal do castelo" << endl;
        cout << "tambem tem um ponto fraco, ele eh vulneravel a ataques rapidos." << endl;
    } else {
    	cout << "\n----------------------------------------------------" << endl;
        cout << "\nSabio Maluco: Entendo, aventureiro. Mas lembre-se, o dragao eh muito perigoso.\nSe voce nao tiver cuidado, ele pode matar voce." << endl;
    }
    
    // Adicionando o Baú da Luz
    cout << "\n----------------------------------------------------" << endl;
    cout << "\nDepois de ter tido uma conversa com o Sabio, voce continua olhando por " << endl;
  	cout << "todas as partes do castelo. Voce entra em varias salas, mas nenhuma " << endl;
  	cout << "aparece ter alguma coisa, voce pensa em desistir de continuar por esse " << endl;
  	cout << "caminho." << endl;
  	cout << "\nApos varias e varias horas dentro do castelo, voce comeca a ver uma sala " << endl;
  	cout << "suspeita, entao, decide entrar nela." << endl;
  	cout << "Voce encontra um bau escondido em um canto escuro." << endl;
  	cout << "Ao abrir, voce encontra um Cajado de Luz e uma Armadura Forjada dentro dele." << endl;
  	cout << "O Cajado de Luz aumenta seu poder de dano na batalha." << endl;
  	cout << "A Armadura Forjada aumenta sua vida em 3 pontos.\n" << endl;
  	
  	cout << "Voce quer pegar o Cajado de Luz?" << endl;
  	cout << "1. Sim, eu quero pegar o cajado." << endl;
  	cout << "2. Nao, eu nao quero pegar o cajado." << endl;
	
	int escolhaCajado;
	cout << "Digite o numero da sua escolha: ";
	cin >> escolhaCajado;
	
	if (escolhaCajado == 1) {
	    // Verifica se o personagem tem a habilidade "Cura Ancestral"
	    if (personagemEscolhido.habilidade1 == "Cura Ancestral") {
	    	cout << "\n----------------------------------------------------" << endl;
	        cout << "\nVoce pegou o Cajado de Luz! Seu ataque aumentou em 2 pontos." << endl;
	        personagemEscolhido.ataque += 1;
	    } else {
	    	cout << "\n----------------------------------------------------" << endl;
	        cout << "\nVoce nao sabe manusear este item, nao pode pega-lo. Somente Marina pode pega-lo" << endl;
	    }
	} 
	else {
		cout << "\n----------------------------------------------------" << endl;
	    cout << "\nVoce decidiu nao pegar o Cajado Luminescente." << endl;
	}

	// Pergunta sobre a Armadura Forjada
	cout << "\n----------------------------------------------------" << endl;
	cout << "\nVoce quer pegar a Armadura Forjada?" << endl;
	cout << "1. Sim, eu quero pegar a armadura." << endl;
	cout << "2. Nao, eu nao quero pegar a armadura." << endl;
	
	int escolhaArmadura;
	cout << "Digite o numero da sua escolha: ";
	cin >> escolhaArmadura;
	
	if (escolhaArmadura == 1) {
		cout << "\n----------------------------------------------------" << endl;
	    cout << "\nVoce pegou a Armadura Forjada! Sua vida aumentou em 3 pontos." << endl;
	    personagemEscolhido.vida += 3; 
	} else {
		cout << "\n----------------------------------------------------" << endl;
	    cout << "\nVoce decidiu nao pegar a Armadura Forjada. Voce continuara com 10 de vida." << endl;
	}


    // Batalha contra o Dragão do Crepúsculo
    float vidaChefe = 18;
    cout << "\n--------------------------------------------------------" << endl;
    cout << "\nAgora que voce achou um bau, ficou mais animado para seguir em frente por " << endl;
  	cout << "aquele caminho." << endl;
  	cout << "Ate que voce comeca a escutar um rugido vindo das partes mais baixas do " << endl;
  	cout << "castelo, entao, voce corre para ver o que eh." << endl;
  	cout << "Quando vai chegando perto, os rugidos comecam a ficar cada vez mais altos e " << endl;
  	cout << "assustadores, quando voce chega na frente da sala..." << endl;	
  	cout << "Voce se depara com um enorme dragao, montando em uma montanha de ouro. A cor " << endl;
  	cout << "de sua pele eh escura, e quando abre a boca o cheiro eh muito podre." << endl;	
  	cout << "Mas esse dragao te ve e comeca a ir em sua direcao..." << endl;


    while (true) { 
        while (vidaChefe > 0 && personagemEscolhido.vida > 0) {
            cout << "\nEscolha sua acao:" << endl;
            cout << "1. Atacar" << endl;
            cout << "2. Defender" << endl;

            int acao;
            cout << "\nDigite o numero da sua acao: ";
            cin >> acao;

            switch (acao) {
                case 1:
                    vidaChefe -= personagemEscolhido.ataque;
                     cout << "\n-----------------------------------------" << endl;
                    cout << "Voce ataca o Dragao do Crepusculo e causa " << personagemEscolhido.ataque << " de dano ." << endl;
                    break;
                case 2:
                	 cout << "\n-----------------------------------------" << endl;
                    cout << "Voce se defende e recebe 1 de dano." << endl;
                    break;
                default:
                	 cout << "\n-----------------------------------------" << endl;
                    cout << "Acao invalida." << endl;
                    break;
            }

            if (vidaChefe > 0) {
                if (acao != 2) {
                    personagemEscolhido.vida -= 2;
                    cout << "\nO Dragao do Crepusculo ataca voce e causa 2 de dano." << endl;
                }
                else {
                    personagemEscolhido.vida -= 1;
                    cout << "\nO Dragao do Crepusculo ataca voce, mas voce se defende e recebe apenas 1 de dano." << endl;
                }
            }

            cout << "\nVida do chefe: " << vidaChefe << endl;
            cout << "Vida do jogador: " << personagemEscolhido.vida << endl;
            cout << "-----------------------------------------" << endl;
        }

        if (vidaChefe <= 0) {
        cout << "\nVoce derrotou o Dragao do Crepusculo!\nAgora voce pode continuar sua jornada normalmente." << endl;
        salvarProgresso(personagemEscolhido, "progresso.txt"); 
        cout << "\n-----------------------------------------" << endl;
        
        // Encontro do Baú da Salvação
        cout << "\nEnquanto voce se recupera da batalha, voce encontra um bau escondido em um canto dentro da sala de onde voce derrotou o dragao." << endl;
        cout << "Voce sai da batalha um pouco ferido, porem achou que seria mais dificil." << endl;
        cout << "Voce decide ir ate esse bau para checar o que tem dentro dele, pois o bau esta brilhando muito." << endl;
        cout << "Voce acha ue tem ouro dentro dele, porem..." << endl;
        cout << "Ao abrir, voce encontra uma Pocao de Cura dentro dele." << endl;
        cout << "Essa pocao te da 5 a mais de vida." << endl;
        
        cout << "\nVoce pode pegar a Pocao de Cura?" << endl;
        cout << "1. Sim, eu quero pegar a pocao." << endl;
        cout << "2. Nao, eu nao quero pegar a pocao." << endl;

        int escolhaPocao;
        cout << "Digite o numero da sua escolha: ";
        cin >> escolhaPocao;

	        if (escolhaPocao == 1) {
	        	 cout << "\n-----------------------------------------" << endl;
	            cout << "\nVoce tomou a Pocao de Cura e recuperou 5 de vida!" << endl;
	            personagemEscolhido.vida += 5; 
	        } else {
	        	cout << "\n-----------------------------------------" << endl;
	            cout << "\nVoce decidiu nao pegar a Pocao de Cura. Voce continuara com " << personagemEscolhido.vida << " de vida." << endl;
	        }
        break; 
    	} else {
            cout << "\nVoce foi derrotado pelo Dragao do Crepusculo." << endl;
            vidaChefe = 18;
            personagemEscolhido.vida = 10;
	        cout << "Voce retorna ao checkpoint e pode enfrentar o chefe novamente." << endl;
	        cout << "-----------------------------------------" << endl;
        }
    }

    // Batalha contra o Cavaleiro Espectral
    vidaChefe = 22;
    cout << "\n----------------------------------------------------------------------------" << endl;
    cout << "\nApos ter tomado a pocao de cura, voce se sente recuperado e com todas as " << endl;
  	cout << "suas energias de volta." << endl;
  	cout << "Ao sair da sala, voce volta a subir as escadas. Voce acha que ja derrotou " << endl;
  	cout << "o monstro do castelo, porem, chegando perto do andar principal..." << endl;
  	cout << "Voce escuta uma voz grossa vindo de perto da sala por onde voce entrou no castelo" << endl;
  	cout << "A voz fala: quem foi que incomodou o dragao?" << endl;
  	cout << "\nEle comeca a vir para cada vez mais perto de voce, entao, voce comeca a se " << endl;
  	cout << "preparar para o que parecer ser mais uma batalha." << endl;
  	cout << "De repente, ele aparece na sua frente. Voce percebe que ele nao eh um " << endl;
  	cout << "cavaleiro normal, ele eh uma alma que fica vagando pelo castelo protegendo-o." << endl;
  	cout << "Sua armadura eh toda escura, e ele comeca a ir em sua direcao perguntando o " << endl;
  	cout << "por que voce incomodou o dragao. Entao, ele comeca a te atacar..." << endl;

	while(true) {
	    while (vidaChefe > 0 && personagemEscolhido.vida > 0) {
	        cout << "\nEscolha sua acao:" << endl;
	        cout << "1. Atacar" << endl;
	        cout << "2. Defender" << endl;
	
	        int acao;
	        cout << "\nDigite o numero da sua acao: ";
	        cin >> acao;
	
	        switch (acao) {
	            case 1:
	                vidaChefe -= personagemEscolhido.ataque;
	                cout << "\n-----------------------------------------" << endl;
	                cout << "Voce ataca o Cavaleiro Espectral e causa " << personagemEscolhido.ataque <<  " de dano." << endl;
	                break;
	            case 2:
	            	cout << "\n-----------------------------------------" << endl;
	                cout << "Voce se defende e recebe 1 de dano." << endl;
	                break;
	            default:
	            	cout << "\n-----------------------------------------" << endl;
	                cout << "Acao invalida." << endl;
	                break;
	        }
	
	        if (vidaChefe > 0) {
	            if (acao != 2) {
	                personagemEscolhido.vida -= 2;
	                cout << "\nO Cavaleiro Espectral ataca voce e causa 2 de dano." << endl;
	            }
	            else {
	                personagemEscolhido.vida -= 1;
	                cout << "\nO Cavaleiro Espectral ataca voce, mas voce se defende e recebe apenas 1 de dano." << endl;
	            }
	        }
	
	        cout << "\nVida do chefe: " << vidaChefe << endl;
	        cout << "Vida do jogador: " << personagemEscolhido.vida << endl;
	        cout << "-----------------------------------------" << endl;
	    }
	
	if (vidaChefe <= 0) {
	        cout << "\nVoce derrotou o Cavaleiro Espectral!\nAgora voce pode continuar sua jornada normalmente." << endl;
	        salvarProgresso(personagemEscolhido, "progresso.txt");
	        cout << "\n-----------------------------------------" << endl;
	
	        // Encontro com Erick
	        cout << "\nApos ter vencido a batalha, voce esta ferido, porem conseguiu enfrentar as " << endl;
    			cout << "criaturas do castelo. Entao, voce comeca a ir em direcao a saida do castelo, " << endl;
    			cout << "que fica no andar principal." << endl;
    			cout << "Chegando perto da saida para continuar seguindo seu caminho ate o reino."  << endl;
    			cout << "Voce encontra alguem proximo a saida do castelo. Eh o espirito de " << endl;
    			cout << "um antigo guardiao do castelo, que esta condenado a vagar entre as muralhas " << endl;
    			cout << "ate o local ser libertado de sua maldicao." << endl;	
    			cout << "Erick: Voce... derrotou as forcas que aprisionavam o castelo. Posso guia-lo " << endl;
    			cout << "ate o reino, mas apenas se provar que nao representa uma nova ameaca..." << endl;

	
	        cout << "\nVoce responde:" << endl;
	        cout << "1. Por que ainda esta aqui? Nao deseja sua liberdade?" << endl;
	        cout << "2. Obrigado, mas posso encontrar meu caminho sozinho." << endl;
	        cout << "3. Preciso apenas de um guia. Sua lealdade ao castelo nao me interessa." << endl;
	
	        int escolhaErick;
	        cout << "\nDigite o numero da sua acao: ";
	        cin >> escolhaErick;
	
	        switch (escolhaErick) {
	            case 1:
	            	  cout << "\n-----------------------------------------" << endl;
	                cout << "\nErick: Eu existo para proteger o que um dia foi o simbolo de honra desta " << endl;
					        cout << "terra, mas esse juramento perdeu o sentido... Eu ajudo voce a sair deste " << endl;
					        cout << "lugar, mas, por favor, liberte minha alma ao contar nossa historia ao rei." << endl;
	                break;
	            case 2:
	            	  cout << "\n-----------------------------------------" << endl;
	                cout << "\nErick: Sozinho voce estara exposto as forcas que ainda vagueiam pelos arredores. Nao subestime o que nao conhece." << endl;
	                break;
	            case 3:
	            	  cout << "\n-----------------------------------------" << endl;
	                cout << "\nErick: Que arrogancia, em... Mas o guiarei, mesmo que suas palavras sejam impiedosas." << endl;
	                break;
	            default:
	            	  cout << "\n-----------------------------------------" << endl;
	                cout << "\nEscolha invalida." << endl;
	                break;
	        }
	
	        // Após batalha
	        cout << "\n---------------------------------------------------------------" << endl;
	        cout << "\nVoce continua sua jornada, agora com a ajuda de Erick ou sozinho, " << endl;
    			cout << "dependendo de sua escolha." << endl;
    			cout << "O caminho ate o reino eh longo e cheio de desafios, mas voce esta " << endl;
    			cout << "determinado a ajudar o rei." << endl;
    			cout << "Depois de horas de caminhada, voce finalmente chega ao reino. O rei " << endl;
    			cout << "o recebe com gratidao e lhe agradece por ter trazido o Amuleto do Crepusculo." << endl;			
    			cout << "O rei lhe diz que o amuleto eh a chave para derrotar o mal que ameaca " << endl;
    			cout << "o reino e que voce eh o unico que pode ajuda-lo a salvar o reino." << endl;	
    			cout << "Voce aceita o desafio e se prepara para enfrentar o mal que ameaca o reino." << endl;

	
	        // Final
	        cout << "\nQuando chega ao castelo do rei, descobre que ele esta gravemente doente, " << endl;
			  cout << "acometido por uma maldicao que so poderia ser quebrada pelo poder de um corajoso aventureiro." << endl;
			  cout << "Voce e chamado aos aposentos reais para encontrar o rei deitado, fraco e sem forcas." << endl;
			  cout << "Rei: Aventureiro, obrigado por responder ao chamado. Eu preciso de sua " << endl;
			  cout << "ajuda... minha vida depende disso." << endl;
			  cout << "Voce se aproxima e percebe que o rei tem uma aura sombria ao redor dele, " << endl;
			  cout << "semelhante a das criaturas que enfrentou no castelo." << endl;
			  cout << "Parece que a maldicao do dragao e da rainha sombria tambem afetou o rei." << endl;

	
	        cout << "\nOpcao de interacao:" << endl;
	        cout << "1. Perguntar sobre a origem da maldicao." << endl;
	        cout << "2. Oferecer sua ajuda para quebrar a maldicao." << endl;
	
	        int escolhaRei;
	        cout << "\nDigite o numero da sua acao: ";
	        cin >> escolhaRei;
	
	        if (escolhaRei == 1) {
  	        	cout << "\n-----------------------------------------" << endl;
	            cout << "\nRei: A maldicao foi colocada por uma antiga alianca de magos sombrios, aqueles mesmos que ja dominaram o Castelo Amaldicoado..." << endl;
	            cout << "so uma forca pura pode neutraliza-la." << endl;
	        } else if (escolhaRei == 2) {
	        	  cout << "\n-----------------------------------------" << endl;
	            cout << "\nRei: Agradeco por sua bravura, aventureiro. Existe uma planta rara chamada 'Erva da Luz Pura,'" << endl;
	            cout << "que cresce apenas nas profundezas do Bosque das Almas. Traga-me essa erva, e acredito que conseguirei me recuperar." << endl;
	        }
			    cout << "\n-----------------------------------------" << endl;
	        cout << "\nVoce embarca em uma nova jornada pelo bosque, enfrentando criaturas sombrias e desafios no caminho." << endl;
	        cout << "Ao encontrar a erva, voce sente uma energia pura e poderosa, e a leva de volta ao rei." << endl;
	
	        cout << "\nAo retornar:" << endl;
	        cout << "Rei:Voce conseguiu, bravo aventureiro! Agora eu posso me curar." << endl;
	        cout << "\nEle ingere a erva, e a aura sombria ao redor dele comeca a desaparecer," << endl;
	        cout << "enquanto ele recupera sua cor e forcas aos poucos." << endl;
	        cout << "\nRei: Sua coragem nao sera esquecida. Por seus feitos heroicos, voce sera sempre bem-vindo em meu reino e tera as honras de um verdadeiro cavaleiro." << endl;
			
			  cout << "\n-----------------------------------------" << endl;
	        cout << "\nCom a gratidao do rei, voce recebe uma medalha de honra e um raro amuleto de protecao, como simbolo de sua bravura e devocao ao reino." << endl;
	        break;
	    } else {
	        cout << "\nVoce foi derrotado pelo Cavaleiro Espectral." << endl;
	        vidaChefe = 22;
	        personagemEscolhido.vida = 10;
		      cout << "Voce retorna ao checkpoint e pode enfrentar o chefe novamente." << endl;
		      cout << "-----------------------------------------" << endl;
	    }
	}
}

// Funcao para a Montanha dos Gigantes
void montanhaDosGigantes(Personagem& personagemEscolhido) {
    cout << "\nA Montanha dos Gigantes eh um lugar perigoso e isolado, onde ventos uivantes " << endl;
    cout << "e tempestades fazem as encostas tremerem. Dizem que a montanha foi lar de uma " << endl;
    cout << "raca de gigantes ha muito esquecida, que se ergueram como protetores de um " << endl;
    cout << "talisma sagrado que confere imenso poder a quem o possui. As cavernas da " << endl;
    cout <<	"montanha sao lar de criaturas estranhas e o caminho eh marcado por armadilhas " << endl;
    cout <<	"naturais, como deslizamentos de pedras e ventos poderosos." << endl;
	  cout << "Enquanto o cavaleiro sobe, ele enfrenta o peso da altitude e a presenca de " << endl;
	  cout << "sombras enormes que se movem entre as nuvens. O silencio eh interrompido por " << endl;
	  cout << "rugidos e o som de rochas caindo, indicando que os gigantes estao atentos aos intrusos." << endl;
	  cout << "\n---------------------------------------------" << endl;

    // Encontro com o Montanhista
    cout << "Voce esta subindo a montanha, e de repente encontra um homem sozinho, o Montanhista." << endl;
    cout << "Montanhista: Ah, um aventureiro! Eu estou perdido aqui ha dias.\nPosso pedir sua ajuda para encontrar o caminho de volta?" << endl;
    cout << "\nVoce aceita ajudar o Montanhista?" << endl;
    cout << "1. Sim, eu vou ajudar." << endl;
    cout << "2. Nao, eu nao tenho tempo." << endl;

    int escolhaMontanhista;
    cout << "\nDigite o numero da sua acao: ";
    cin >> escolhaMontanhista;
    
	float defesa = 0;
	
	if (escolhaMontanhista == 1) {
		  cout << "\n---------------------------------------------" << endl;
	    personagemEscolhido.ataque += 0.5; 
	    cout << "\nMontanhista: Obrigado, aventureiro! Eu posso ajudar voce a " << endl;
		  cout << "encontrar o caminho para o topo da montanha. Mas primeiro, voce precisa " << endl;
		  cout << "me ajudar a encontrar um bau escondido que contem um escudo que pode " << endl;
		  cout <<  "proteger voce dos ataques dos gigantes." << endl;		
		  cout << "\nVoce encontra o bau escondido e dentro dele encontra um Escudo de Granito." << endl;		
		  cout << "O Escudo de Granito reduz o dano de ataques pesados e oferece defesa extra " << endl;
		  cout << "contra esmagamento." << endl;

	    cout << "\nVoce quer pegar o Escudo de Granito?" << endl;
	    cout << "1. Sim, eu quero pegar o escudo." << endl;
	    cout << "2. Nao, eu nao quero pegar o escudo." << endl;
	
	    int escolhaEscudo;
	    cout << "\nDigite o numero da sua acao: ";
	    cin >> escolhaEscudo;
	
	    if (escolhaEscudo == 1) {
	    cout << "\n---------------------------------------------" << endl;
	    cout << "\nVoce pegou o Escudo de Granito! Agora, quando voce se defender, recebera apenas 0.5 de dano." << endl;
	    cout << "\n---------------------------------------------" << endl;
	    defesa = 0.5; 
	    cout << "\nAgora que voce achou o bau, voce se sente mais protegido e preparado." << endl;
	    cout << "Entao, voce continua seguindo seu caminho em busca de ajudar o rei. Voce " << endl;
			cout << "esta cada vez mais alto na montanha, quando olha pra baixo ja nao tem mais " << endl;
			cout << "volta a nao ser continuar seu caminho." << endl;			
			cout << "Chegando quase no topo, voce comeca a escutar sons de passos muito altos, " << endl;
			cout << "que nao parecem de algum animal normal ou de uma pessoa." << endl;			
			cout << "Voce fica assustado, porem, continua seguindo o seu caminho. E quando chega " << endl;
			cout << "no topo, ve um amontoado gigante de pedras. Mas nao sao so pedras, elas " << endl;
			cout << "estao se movendo, tem bracos e pernas gigantes. Eh o gigante..." << endl;
	    }
		else {
	    cout << "\n---------------------------------------------" << endl;
	    cout << "\nVoce decidiu nao pegar o Escudo de Granito." << endl;
	    cout << "\n---------------------------------------------" << endl;
	    cout << "Entao, voce continua seguindo seu caminho em busca de ajudar o rei. Voce " << endl;
			cout << "esta cada vez mais alto na montanha, quando olha pra baixo ja nao tem mais " << endl;
			cout << "volta a nao ser continuar seu caminho." << endl;			
			cout << "Chegando quase no topo, voce comeca a escutar sons de passos muito altos, " << endl;
			cout << "que nao parecem de algum animal normal ou de uma pessoa." << endl;			
			cout << "Voce fica assustado, porem, continua seguindo o seu caminho. E quando chega " << endl;
			cout << "no topo, ve um amontoado gigante de pedras. Mas nao sao so pedras, elas " << endl;
			cout << "estao se movendo, tem bracos e pernas gigantes. Eh o gigante..." << endl;
	    }
	} 
	else {
		cout << "\n---------------------------------------------" << endl;
	  cout << "\nMontanhista: Entendo, aventureiro. Mas lembre-se, a montanha eh muito perigosa.\nSe voce nao tiver cuidado, os gigantes podem matar voce." << endl;
	  cout << "\nEntao, voce continua seguindo seu caminho em busca de ajudar o rei. Voce " << endl;
		cout << "esta cada vez mais alto na montanha, quando olha pra baixo ja nao tem mais " << endl;
		cout << "volta a nao ser continuar seu caminho." << endl;			
		cout << "Chegando quase no topo, voce comeca a escutar sons de passos muito altos, " << endl;
		cout << "que nao parecem de algum animal normal ou de uma pessoa." << endl;			
		cout << "Voce fica assustado, porem, continua seguindo o seu caminho. E quando chega " << endl;
		cout << "no topo, ve um amontoado gigante de pedras. Mas nao sao so pedras, elas " << endl;
		cout << "estao se movendo, tem bracos e pernas gigantes. Eh o gigante..." << endl;
	}

	// Batalha contra o Gigante Rochoso
	float vidaChefe = 18;
	cout << "\n---------------------------------------------" << endl;
	cout << "\nO Gigante Rochoso eh um gigante feito de pedras e minerais da montanha, ele possui uma resistencia absurda" << endl;
	cout << "e ataques brutais que causam tremores.\nCada golpe faz a terra tremer, criando fissuras no solo que o cavaleiro deve evitar." << endl;
	cout << "De repente, ele te avista e comeca a ir em sua direcao..." << endl;
	
	while (true) { 
	    while (vidaChefe > 0 && personagemEscolhido.vida > 0) {
	        cout << "\nEscolha sua acao:" << endl;
	        cout << "1. Atacar" << endl;
	        cout << "2. Defender" << endl;
	
	        int acao;
	        cout << "\nDigite o numero da sua acao: ";
	        cin >> acao;
	
	        switch (acao) {
	            case 1:
	                vidaChefe -= personagemEscolhido.ataque;
	                cout << "\n---------------------------------------------" << endl;
	                cout << "Voce ataca o Gigante Rochoso e causa " << personagemEscolhido.ataque << " de dano." << endl;
	                break;
	            case 2:
	                if (defesa > 0) {
	                	cout << "\n---------------------------------------------" << endl;
	                    cout << "Voce se defende e recebe " << (1 - defesa) << " de dano." << endl; 
	                    personagemEscolhido.vida -= (1 - defesa); 
	                } else {
	                	cout << "\n---------------------------------------------" << endl;
	                    cout << "Voce se defende e recebe 1 de dano." << endl;
	                    personagemEscolhido.vida -= 1; 
	                }
	                break;
	            default:
	            	cout << "\n---------------------------------------------" << endl;
	                cout << "Acao invalida." << endl;
	                break;
	        }
	
	        if (vidaChefe > 0) {
	            if (acao != 2) {
	                personagemEscolhido.vida -= 2;
	                cout << "\nO Gigante Rochoso ataca voce e causa 2 de dano." << endl;
	            } else {
	                cout << "\nO Gigante Rochoso ataca voce, mas voce se defende." << endl;
	            }
	        }
	
	        cout << "\nVida do chefe: " << vidaChefe << endl;
	        cout << "Vida do jogador: " << personagemEscolhido.vida << endl;
	        cout << "---------------------------------------------" << endl;
	    }
	
	        if (vidaChefe <= 0) {
	            cout << "\nVoce derrotou o Gigante Rochoso!\nAgora voce pode continuar sua jornada normalmente." << endl;
	            salvarProgresso(personagemEscolhido, "progresso.txt"); 
	            break; 
	        } else {
	            cout << "\nVoce foi derrotado pelo Gigante Rochoso." << endl;
	            vidaChefe = 18;
	            personagemEscolhido.vida = 10;
	            cout << "\nVoce retorna ao checkpoint e pode enfrentar o chefe novamente." << endl;
	            cout << "\n---------------------------------------------" << endl;
	        }
	    }

    // Encontro com o Emerson
    cout << "\n---------------------------------------------" << endl;
    cout << "\nApos ter derrotado o Gigante Rochoso, voce continua subindo a montanha, " << endl;	
	  cout << "mesmo que tenha sido uma batalha dificil e voce saiu ferido." << endl;	
	  cout << "Voce esta decido em encontrar o rei e ajuda-lo, nada pode o parar. Entao, " << endl;	
	  cout << "agora que voce ja esta no topo da montanha, voce precisa chegar ate o outro lado dela." << endl;	
	  cout << "Voce continua seguindo, ja nao esta aguentando mais os ventos frios que " << endl;	
	  cout << "fazem no topo e andar, ate que voce encontra um homem sozinho no meio da montanha..." << endl;	
	  cout << "Emerson: Ah, um aventureiro! Eu estou aqui ha anos, estudando a montanha e " << endl;	
	  cout << "seus segredos.\nPosso ajudar voce a encontrar o caminho para o topo da montanha." << endl;

    cout << "\nVoce aceita a ajuda do Emerson?" << endl;
    cout << "1. Sim, eu vou aceitar." << endl;
    cout << "2. Nao, eu nao preciso de ajuda." << endl;

    int escolhaEmerson;
    cout << "Digite o numero da sua acao: ";
    cin >> escolhaEmerson;

    if (escolhaEmerson == 1) {
        personagemEscolhido.ataque += 0.5;
        cout << "\n---------------------------------------------" << endl;
        cout << "\nEmerson: Obrigado, aventureiro! Eu posso ajudar voce a encontrar o caminho para o outro lado da montanha." << endl;
        cout << "Mas primeiro, voce precisa saber que o Gigante de Aco esta la, e ele eh muito perigoso." << endl;
        cout << "\nVoce quer saber mais sobre o Gigante de Aco?" << endl;
        cout << "1. Sim, eu quero saber mais." << endl;
        cout << "2. Nao, eu nao quero saber mais." << endl;

        int escolhaGigante;
        cout << "Digite o numero da sua acao: ";
        cin >> escolhaGigante;

        if (escolhaGigante == 1) {
        	cout << "\n---------------------------------------------" << endl;
            cout << "\nEmerson: O Gigante de Aco eh uma maquina de destruicao.\nCom uma armadura feita de aco bruto, ele empunha uma clava que deixa crateras onde atinge." << endl;
            cout << "A defesa do Gigante de Aco eh quase impenetravel, exceto em pontos estrategicos que o cavaleiro deve atingir com precisao e rapidez." << endl;
        } 
		else {
        	cout << "\n---------------------------------------------" << endl;
            cout << "\nEmerson: Entendo, aventureiro. Mas lembre-se, o Gigante de Aco eh muito perigoso.\nSe voce nao tiver cuidado, ele pode matar voce ." << endl;
        }
    } 
	else {
    	cout << "\n---------------------------------------------" << endl;
        cout << "\nEmerson: Entendo, aventureiro. Mas lembre-se, a montanha eh muito perigosa.\nSe voce nao tiver cuidado, os gigantes podem matar voce." << endl;
    }

    // Encontro com o Bau da Tempestade
    cout << "\nApos ter passado pelo Emerson, voce continua subindo a montanha.\nAte que voce encontra um bau escondido, o Bau da Tempestade." << endl;
    cout << "Ao abrir, voce encontra uma Armadura dentro dele, a armadura da tempestade." << endl;
    cout << "Essa Armadura te da mais 4 de vida e te deixa mais protegido contra criaturas." << endl;
    cout << "\nVoce quer pegar essa Armadura?" << endl;
    cout << "1. Sim, eu quero pegar a Armadura." << endl;
    cout << "2. Nao, eu nao quero pegar a Armadura." << endl;

    int escolhaArmadura;
    cout << "Digite o numero da sua acao: ";
    cin >> escolhaArmadura;

    if (escolhaArmadura == 1) {
    	cout << "\n---------------------------------------------" << endl;
        cout << "\nVoce pegou a Armadura da Tempestade! Sua vida aumentou." << endl;
        personagemEscolhido.vida += 4;
    } 
	else {
    	cout << "\n---------------------------------------------" << endl;
        cout << "\nVoce decidiu nao pegar a Armadura da Tempestade." << endl;
    }

    // Batalha contra o Gigante de Aco
    vidaChefe = 22;
    cout << "\n---------------------------------------------" << endl;
    cout << "\nAgora que voce achou o Bau da Tempestade, voce continua caminhando pela " << endl;
	  cout << "montanha. Mas voce ja esta muito cansado de tanto andar e escalar essa " << endl;
	  cout << "montanha, entao, voce decide sentar um pouco." << endl;	
	  cout << "Quando finalmente voce senta, voce avista um enorme gigante feito de ferro e " << endl;
	  cout << "aco vindo em sua direcao..." << endl;	
	  cout << "O Gigante de Aco eh uma maquina de destruicao. Com uma armadura feita de aco " << endl;
	  cout << "bruto, ele empunha uma clava que deixa crateras onde atinge. A defesa do " << endl;
	  cout << "Gigante de Aco eh quase impenetravel, exceto em pontos estrategicos que o " << endl;
	  cout << "cavaleiro deve atingir com precisao e rapidez." << endl;


    while (true) { 
        while (vidaChefe > 0 && personagemEscolhido.vida > 0) {
            cout << "\nEscolha sua acao:" << endl;
            cout << "1. Atacar" << endl;
            cout << "2. Defender" << endl;

            int acao;
            cout << "\nDigite o numero da sua acao: ";
            cin >> acao;

            switch (acao) {
                case 1:
                	cout << "\n---------------------------------------------" << endl;
                    vidaChefe -= personagemEscolhido.ataque;
                    cout << "Voce ataca o Gigante de Aco e causa " << personagemEscolhido.ataque << " de dano." << endl;
                    break;
                case 2:
                	cout << "\n---------------------------------------------" << endl;
                    if (defesa > 0) {
                    cout << "Voce se defende e recebe " << (1 - defesa) << " de dano." << endl; 
                    personagemEscolhido.vida -= (1 - defesa); 
                } else {
                	cout << "\n---------------------------------------------" << endl;
                    cout << "Voce se defende e recebe 1 de dano." << endl;
                    personagemEscolhido.vida -= 1; 
                }
                    break;
                default:
                	cout << "\n---------------------------------------------" << endl;
                    cout << "Acao invalida." << endl;
                    break;
            }

            if (vidaChefe > 0) {
                if (acao != 2) {
                    personagemEscolhido.vida -= 2;
                    cout << "\nO Gigante de Aco ataca voce e causa 2 de dano." << endl;
                }
                else {
                    personagemEscolhido.vida -= 1 ;
                    cout << "\nO Gigante de Aco ataca voce, mas voce se defende e recebe apenas 1 de dano." << endl;
                }
            }

            cout << "\nVida do chefe: " << vidaChefe << endl;
            cout << "Vida do jogador: " << personagemEscolhido.vida << endl;
            cout << "---------------------------------------------" << endl;
        }

        if (vidaChefe <= 0) {
            cout << "\nVoce derrotou o Gigante de Aco e agora voce tem o Talisma sagrado!\nAgora voce pode continuar sua jornada normalmente." << endl;
            salvarProgresso(personagemEscolhido, "progresso.txt"); 
            cout << "\n---------------------------------------------" << endl;
            break; 
        } else {
            cout << "\nVoce foi derrotado pelo Gigante de Aco." << endl;
            vidaChefe = 22;
            personagemEscolhido.vida = 10;
            cout << "\nVoce retorna ao checkpoint e pode enfrentar o chefe novamente." << endl;
            cout << "\n---------------------------------------------" << endl;
        }
    }
    
     // Encontro com A Voz da Montanha
    cout << "\nApos derrotar os dois chefes na Montanha dos Gigantes e conquistar o " << endl;
	  cout << "talisma sagrado, o cavaleiro sente o peso da batalha e da longa escalada." << endl;
	  cout << "A neblina se dispersa ligeiramente, revelando uma figura alta e encapuzada a sua frente." << endl;
	  cout << "A Voz da Montanha: Voce sobreviveu as tempestades e aos guardioes desta " << endl;
	  cout << "montanha. O talisma agora eh seu." << endl;
	  cout << "Mas o caminho de volta eh traicoeiro, e ha forcas que desejam tirar de voce " << endl;
	  cout << "o que conquistou. Devo guia-lo? Ou prefere seguir por sua propria conta?" << endl;
    cout << "1. Sim, aceito sua ajuda." << endl;
    cout << "2. Nao, eu prefiro seguir sozinho." << endl;
    cout << "3. Antes de decidir, me diga: por que quer me ajudar?" << endl;

    int escolhaVoz;
    cout << "\nDigite o numero da sua acao: ";
    cin >> escolhaVoz;

    if (escolhaVoz == 1) {
    	cout << "\n---------------------------------------------" << endl;
        cout << "\nA Voz da Montanha: Sabia escolha. O poder do talisma atrai a cobica de " << endl;
		cout << "muitos. Eu conheco atalhos e passagens seguras para evitar seus perseguidores." << endl;
		cout << "A Voz da Montanha guia o cavaleiro por um caminho escondido entre as rochas " << endl;
		cout << "e, no caminho, compartilha historias sobre os antigos gigantes e sua missao " << endl;
		cout << "de proteger o talisma." << endl;
		cout << "\nEle da conselhos sobre o uso do talisma e fala das suas responsabilidades como portador." << endl;
		cout << "Ao chegarem proximos ao reino, ele faz uma ultima reverencia." << endl;
		cout << "A Voz da Montanha: Va em paz, cavaleiro. Que o talisma seja uma forca para o bem." << endl;
		cout << "O cavaleiro retorna ao reino, onde eh recebido com honras pelo rei." << endl;

    } 
	else if (escolhaVoz == 2) {
    cout << "\n---------------------------------------------" << endl;
    cout << "\nA Voz da Montanha: Muito bem, que a coragem seja sua aliada, mas lembre-se: " << endl;
		cout << "muitos desejam o poder que voce carrega agora. Evite as trilhas abertas e " << endl;
		cout << "mantenha-se atento." << endl;		
		cout << "O cavaleiro segue seu proprio caminho, enfrentando alguns obstaculos, como " << endl;
		cout << "rochas desmoronando e criaturas menores atraidas pelo talisma." << endl;		
		cout << "A jornada eh solitaria, e ele percebe que alguns caminhos levam a armadilhas, " << endl;
		cout << "mas sua determinacao o ajuda a superar os desafios." << endl;		
		cout << "Ao finalmente chegar ao reino, exausto, ele eh recebido pelo rei, que o aguarda ansiosamente." << endl;
    } 
	else if (escolhaVoz == 3) {
    	  cout << "\n---------------------------------------------" << endl;
        cout << "\nA Voz da Montanha: Eu nao desejo o talisma, mas fui designado para proteger o poder que ele representa." << endl;
        cout << "Quando vejo alguem digno o bastante para reclama-lo, ofereco minha ajuda." << endl;
        cout << "O cavaleiro pondera a resposta e pode entao escolher:" << endl;
        cout << "1. Nesse caso, aceito sua ajuda." << endl;
        cout << "2. Agradeco, mas vou continuar sozinho." << endl;

        int escolhaVoz2;
        cout << "\nDigite o numero da sua acao: ";
        cin >> escolhaVoz2;

  if (escolhaVoz2 == 1) {
      cout << "\n---------------------------------------------" << endl;
      cout << "\nA Voz da Montanha: Sabia escolha. O poder do talisma atrai a cobica de " << endl;
			cout << "muitos. Eu conheco atalhos e passagens seguras para evitar seus perseguidores." << endl;
			cout << "A Voz da Montanha guia o cavaleiro por um caminho escondido entre as rochas " << endl;
			cout << "e, no caminho, compartilha historias sobre os antigos gigantes e sua missao " << endl;
			cout << "de proteger o talisma." << endl;
			cout << "Ele da conselhos sobre o uso do talisma e fala das suas responsabilidades como portador." << endl;		
			cout << "Ao chegarem proximos ao reino, ele faz uma ultima reverencia." << endl;			
			cout << "A Voz da Montanha: Va em paz, cavaleiro. Que o talisma seja uma forca para o bem." << endl;			
			cout << "O cavaleiro retorna ao reino, onde eh recebido com honras pelo rei." << endl;
        } 
		else if (escolhaVoz2 == 2) {
      cout << "\n---------------------------------------------" << endl;
      cout << "\nA Voz da Montanha : Muito bem, que a coragem seja sua aliada, mas lembre-se: " << endl;
			cout << "muitos desejam o poder que voce carrega agora. Evite as trilhas abertas e " << endl;
			cout << "mantenha-se atento." << endl;		
			cout << "\nO cavaleiro segue seu proprio caminho, enfrentando alguns obstaculos, como " << endl;
			cout << "rochas desmoronando e criaturas menores atraidas pelo talisma." << endl;			
			cout << "A jornada eh solitaria, e ele percebe que alguns caminhos levam a armadilhas, " << endl;
			cout << "mas sua determinacao o ajuda a superar os desafios." << endl;			
			cout << "Ao finalmente chegar ao reino, exausto, ele eh recebido pelo rei, que o " << endl;
			cout << "aguarda ansiosamente." << endl;
        }
    }
    
    // Final
    cout << "\n---------------------------------------------" << endl;
    cout << "\nRei: Meu bravo cavaleiro... soube que encontrou o talisma. Minha saude " << endl;
	  cout << "enfraquece a cada dia, e so essa reliquia pode restaurar minhas forcas." << endl;
	  cout << "Voce se aproxima e, ao ativar o poder do talisma, um brilho suave envolve " << endl;
	  cout << "o rei, restaurando lentamente sua vitalidade. Ele sente o efeito e sorri " << endl;
	  cout << "para voce, ja demonstrando sinais de recuperacao." << endl;

    cout << "Rei: Voce trouxe esperanca ao reino mais uma vez. Diga-me, cavaleiro, ha algo que deseja em troca?" << endl;
    cout << "Aqui, voce tem uma escolha:" << endl;
    cout << "1. Pedir uma recompensa material: o rei lhe concede uma quantia em ouro e uma armadura especial como agradecimento." << endl;
    cout << "2. Pedir ajuda para seu vilarejo: o rei promete reforcos e melhorias para o vilarejo de onde voce veio." << endl;
    cout << "3. Nao pedir nada, apenas servir o reino: o rei fica tocado pela sua lealdade e promete um lugar de honra em seu conselho." << endl;

    int escolhaRecompensa;
    cout << "\nDigite o numero da sua acao: ";
    cin >> escolhaRecompensa;

    if (escolhaRecompensa == 1) {
    	  cout << "\n---------------------------------------------" << endl;
        cout << "\nRei: Muito bem, cavaleiro. Voce recebera uma recompensa material por seus servicos." << endl;
        cout << "Aqui esta uma quantia em ouro e uma armadura especial para voce." << endl;
    } 
	else if (escolhaRecompensa == 2) {
		    cout << "\n---------------------------------------------" << endl;
        cout << "\nRei: Ah, cavaleiro, voce eh um verdadeiro heroi. Seu vilarejo recebera reforcos e melhorias," << endl;
        cout << "e voce sera sempre lembrado como um defensor do reino." << endl;
    } 
	else if (escolhaRecompensa == 3) {
		    cout << "\n---------------------------------------------" << endl;
        cout << "\nRei: Cavaleiro, sua lealdade eh inspiradora. Voce tera um lugar de honra em meu conselho," << endl;
        cout << "e juntos, governaremos o reino com justica e sabedoria." << endl;
    }

    cout << "\nO rei, agora revigorado, levanta-se e agradece publicamente sua bravura, " << endl;
	  cout << "declarando um dia de celebracao em sua homenagem." << endl;
	  cout << "Assim, voce encerra mais uma jornada como o grande heroi do reino, sabendo " << endl; 
	  cout << "que sua lealdade e sacrificio ajudaram a salvar nao apenas o rei, mas tambem " << endl;
	  cout << "o futuro do reino." << endl;
}  

int main() {
	cout << "Bem-Vindo a Aventura dos Cavaleiros!" << endl;
	cout << "Para comecar, escolha o seu personagem:" << endl;
	cout << "----------------------------------------" << endl;
    // Definindo os personagens
    Personagem personagens[5] = {
        {"Arthur, o Cacador", 10, 8, 4, 9, "Tiro Certeiro", "N/A", "Rapido e calculista."},
        {"Marina, a Feiticeira", 10, 6, 5, 6, "Cura Ancestral", "Escudo Elemental", "Compassiva e sabia."},
        {"Richard, o Guardiao", 10, 7, 7, 5, "Espada do Destino", "Postura de Defesa", "Corajoso e implacavel."},
        {"Valeria, a Guerreira", 10, 6, 8, 6, "Golpe Radiante", "Investida da Justica", "Forte e determinada."},
        {"Edgar, o Mestre Sombrio", 10, 7, 3, 10, "Laminas Envenenadas", "Desaparecer nas Sombras", "Silencioso e letal."}
    };

    int numPersonagens = sizeof(personagens) / sizeof(personagens[0]);

    // Escolher personagem
    int indiceEscolhido = escolherPersonagem(personagens, numPersonagens);
    Personagem personagemEscolhido = personagens[indiceEscolhido];

    // Exibir informações do personagem escolhido
    exibirInformacoesPersonagem(personagemEscolhido);

    // Salvar progresso
    salvarProgresso(personagemEscolhido, "progresso.txt");

    // Carregar progresso
    Personagem personagemCarregado;
    carregarProgresso(personagemCarregado, "progresso.txt");

    cout << "\nPersonagem carregado: " << personagemCarregado.nome << endl;
    cout << "\n----------------------------------------------" << endl;

    // Iniciar a cena inicial
    cenaInicial(personagemEscolhido);

    return 0;
}
