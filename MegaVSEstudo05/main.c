//Criar a pasta "res" na raiz do projeto
//Dentro da res criar o arquivo "sprites.res"
//Criar a pasta "sprites" onde ficarão os arquivos de imagens de personagens, inimigos e itens
//Criar o arquivo "gfx.res"
//Criar a pasta "gfx" para guardar os arquivos de tela e background
//Lembrando que a pasta tem que ter o mesmo nome do arquivo ".res"

#include <genesis.h>
#include "sprites.h"

static void MeuImput();

int posicaoX = 0;
int posicaoY = 0;

int main() {

	//Desabilita Interrupt quando acessa VDP
	SYS_disableInts();

	//Inicia Processador de Video VDP, e estabelece resolução da tela 320x224
	VDP_init();
	SPR_init();
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();

	//Inicializar Motos de Sprites
	SPR_init();

	//Reabilita Interrupts quando finaliza acesso VDP
	SYS_enableInts();

	//Cria o ponteiro da Sprite
	Sprite* player;

	player = SPR_addSprite(&personagem, posicaoX, posicaoY, PAL0);
	VDP_setPalette(PAL0, personagem.palette->data);

	while (TRUE) {

		MeuImput(player);
		SPR_update();
		VDP_waitVSync();
	}

	return 0;
}

void MeuImput(Sprite* sprite) {
	u16 valor = JOY_readJoypad(JOY_1);

	//Direcionais
	if (valor & BUTTON_UP) {
		posicaoY -= 5;
	}
	else if (valor & BUTTON_DOWN) {
		posicaoY += 5;
	}
	if (valor & BUTTON_LEFT) {
		posicaoX -= 5;
	}
	else if (valor & BUTTON_RIGHT) {
		posicaoX += 5;
	}

	SPR_setPosition(sprite, posicaoX, posicaoY);
}