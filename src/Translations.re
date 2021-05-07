let russianTranslate = copy => {
  switch (copy) {
  | "Overview" => {j|Разработчики|j}
  | "Mina Overview" => {j|Обзор Mina|j}
  | "Getting Started" => {j|Начало работы|j}
  | "Using Mina" => {j|Использование Мины|j}
  | "Keypair Generation" => {j|Генерация Keypair|j}
  | "Connect to the Network" => {j|Подключение к сети|j}
  | "Sending a Payment" => {j|Отправка платежей с Mina|j}
  | "Staking & Snarking" => {j|Стейкинг и снаркинг|j}
  | "CLI Reference" => {j|Справка по CLI|j}
  | "Advanced" => {j|Передовой|j}
  | "Archive Node" => {j|Архивная нода|j}
  | "Archive Redundancy" => {j|Архивное резервирование|j}
  | "Data Querying" => {j|Запросы данных для операторов нод|j}
  | "Block Producer Sidecar" => {j|Sidecar для блок-продюсера|j}
  | "Client SDK" => {j|Клиентский SDK|j}
  | "Devnet" => {j|Подключение к Devnet|j}
  | "Foundation Delegation" => {j|Рекомендации по участию в программе делегирования Mina Foundation|j}
  | "Hard Fork" => {j|Хардфорк|j}
  | "Hot/Cold Wallets" => {j|Горячее / холодное создание блоков|j}
  | "Ledger Hardware Wallet" => {j|Аппатный кошелек Ledger|j}
  | "Seed Peers" => {j|Сид-пиры|j}
  | "Staking Service Guidelines" => {j|Рекомендации по стейкингу|j}
  | "Developers" => {j|Разработчики|j}
  | "Codebase Overview" => {j|Обзор кодовой базы|j}
  | "Repository Structure" => {j|Структура репозитория|j}
  | "BIP44 Information" => {j|Информация о BIP44|j}
  | "Code Reviews" => {j|Руководящие принципы пересмотра кода|j}
  | "Style Guide" => {j|Руководство по стилю|j}
  | "Sandbox Node" => {j|Нода песочницы|j}
  | "GraphQL API" => {j|GraphQL API|j}
  | "Logging" => {j|Логгинг|j}
  | "Protocol Architecture" => {j|Архитектура протокола|j}
  | "Lifecycle of a Payment" => {j|Жизненный цикл транзакций|j}
  | "Block Producers" => {j|Блок-продюсеры|j}
  | "What's in a Block" => {j|Что в блоке?|j}
  | "Consensus" => {j|Абстракция механизма консенсуса|j}
  | "Proof of Stake" => {j|Proof of Stake|j}
  | "Snark Workers" => {j|Введение|j}
  | "Scan State" => {j|Scan State|j}
  | "Time-locked Accounts" => {j|Временно заблокированные аккаунты|j}
  | "Snapps" => {j|Snapps|j}
  | "Tokens" => {j|Токены|j}
  | "SNARKs" => {j|SNARKs|j}
  | "Getting started using SNARKs" => {j|Начало работы с SNARKs|j}
  | "Which SNARK is right for me?" => {j|Какой SNARK мне подходит?|j}
  | "The snarkyjs-crypto library" => {j|Библиотека snarkyjs-crypto|j}
  | "The snarky-universe library" => {j|Библиотека вселенной snkary|j}
  | "Troubleshooting" => {j|Поиск проблем|j}
  | "Glossary" => {j|Глоссарий|j}
  | "FAQ" => {j|FAQ|j}
  | "Documentation" => {j|Документация|j}
  | "Contributing to Mina" => {j|Участие в развитии Mina|j}
  | "Edit" => {j|Редактировать|j}
  | "Mina Documentation" => {j|Документация Mina|j}
  | _ => ""
  };
};

let translate = (language, copy) => {
  Context.LanguageContext.(
    switch (language) {
    | English => copy
    | Russian => russianTranslate(copy)
    }
  );
};
