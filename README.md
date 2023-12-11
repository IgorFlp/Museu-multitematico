Software de gerenciamento para Museu

Contexto
Os softwares foram desenvolvidos com o intuito de organizar o funcionamento de um museu multitematico sendo dividido em 3 softwares, desenvolvido completamente em linguagem C.

Software Bilheteria
O software tem como operador um funcionário do museu, que guia o visitante pela compra dos temas, calcula o total a pagar, gera um numero aleatorio de ticket e coleta as informações do visitante, exportando todas as informações para o arquivo "Bilheteria.csv", na porta de cada tema outro funcionario utiliza a função "Validação" para checar a existencia dos tickets em cada tema no arquivo "Bilheteria.csv".


Software Terminal
O software tem a função de exibir uma descrição da obra exibida ao seu lado no museu, onde um funcionario escolhe primeiramente o numero do tema de 1 a 3, e depois qual obra sera de 1 a 5, iniciando o ciclo de exibição das descrições, os visitantes são convidados a responder um questionario sobre a obra e avaliar a obra, ao final do dia o funcionario preenche o numero de ticket "9999" para finalizar o ciclo, salvando os numeros de ticket, acertos e avaliações em um arquivo csv que é nomeado durante o programa por exemplo "T1O1.csv" sendo o csv dos dados da obra 1 do tema 1.

Software Central
O software de server tem uma função central de importar os dados de "Bilheteria.csv" e dos csvs dos terminais, guardando os csvs em uma matriz de dados referente as avaliações, fazendo um calculo da nota média dada a cada quadro, depois a nota media do tema, e comparando cada quadro a média do tema, para auxiliar a diretoria do museu na tomada de decisões quanto a permanencia das obras ou dos temas, podendo futuramente ter mais funcões cruzando os dados da bilheteria em uma plataforma de analise de dados.