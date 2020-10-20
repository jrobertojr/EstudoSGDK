# EstudoSGDK
Estudo para desenvolvimento de Jogos para Mega Drive / Sega Genesis


Observação: Este estudo está sendo feito com o SGDK 1.41 
Link: https://github.com/Stephane-D/SGDK/releases

Em primeiro logar deve ser criada as variaveis de ambiente <b>'GDK -- "C:/SGDK"'</b> e <b>'GDKWIN -- "C:\SGDK"'</b></br>

Se utilizar Visual Studio crie um projeto C++ MakeFile e 
em "Linha de comando de build" coloque o seguinte codigo:</br>
<b>"%GDK_WIN%\bin\make -f %GDK_WIN%\makefile.gen"</b>

Em seguida quando abrir a interface do visual temos que especificar
o diretório de inclusão, botão direito no projeto e em seguida propiedades,
em seguida clique em "Diretório VC++" e adicione a pasta "C:\SGDK\inc" em
"Diretórios de Inclusão", depois é só criar uma classe "main.c" com o metodo
"int main()" e está tudo pronto para começar, lembrando que para compilar
temos que compilar somente o projeto e executar o arquivo "rom.bin"
incluido na pasta "out" do projeto.
