//Criar a pasta "res" na raiz do projeto
//Dentro da res criar o arquivo "sprites.res"
//Criar a pasta "sprites" onde ficarão os arquivos de imagens de personagens, inimigos e itens
//Criar o arquivo "gfx.res"
//Criar a pasta "gfx" para guardar os arquivos de tela e background
//Lembrando que a pasta tem que ter o mesmo nome do arquivo ".res"

#include <genesis.h>
#include "sprites.h"
#include "gfx.h"

static void MeuImput();
static int Colisao(int x, int xObjeto, int y, int yObjeto);

int posicaoX = 152;
int posicaoY = 160;

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

	VDP_drawImageEx(PLAN_A, &background, TILE_ATTR_FULL(PAL1, 0, 0, 0, 1), 0, 0, 0, CPU);
	VDP_setPalette(PAL1, background.palette->data);

	while (TRUE) {

		MeuImput(player);
		LimiteTela();

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

// Definindo tamanho da Tela
void LimiteTela() {
	if (posicaoX <= 0)
		posicaoX = 0;
	if (posicaoX + 32 >= 320)
		posicaoX = 320 - 32;
	if (posicaoY <= 0)
		posicaoY = 0;
	if (posicaoY + 32 >= 224)
		posicaoY = 224 - 32;
}

// Verificação de colisão
int Colisao(int x, int xObjeto, int y, int yObjeto) {
	if (x < xObjeto || x > xObjeto + 32 || y < yObjeto || y > yObjeto + 32) {
		return 0;
	}
	else
		return 1;
}