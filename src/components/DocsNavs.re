module DocsNavsTranslations = {
  open ReactIntl;
  let minaOverview = {
    id: "sidenav.mina-overview",
    defaultMessage: "Mina Overview",
  };
  let gettingStarted = {
    id: "sidenav.getting-started",
    defaultMessage: "Getting Started",
  };
  let usingMina = {id: "sidenav.using-mina", defaultMessage: "Using Mina"};
  let keypairGeneration = {
    id: "sidenav.keypair-generation",
    defaultMessage: "Keypair Generation",
  };
  let connectToNetwork = {
    id: "sidenav.connect-to-network",
    defaultMessage: "Connect To The Network",
  };
  let sendPayment = {
    id: "sidenav.sending-a-payment",
    defaultMessage: "Sending a Payment",
  };
  let stakingSnarking = {
    id: "sidenav.staking-snarking",
    defaultMessage: "Staking & Snarking",
  };
  let cliReference = {
    id: "sidenav.cli-reference",
    defaultMessage: "CLI Reference",
  };
  let advanced = {id: "sidenav.advanced", defaultMessage: "Advanced"};
  let archiveNode = {
    id: "sidenav.archive-node",
    defaultMessage: "Archive Node",
  };
  let archiveRedundancy = {
    id: "sidenav.archive-redundancy",
    defaultMessage: "Archive Redundancy",
  };
  let blockProducerSidecar = {
    id: "sidenav.bp-producer-sidecar",
    defaultMessage: "Block Producer Sidecar",
  };
  let clientSDK = {id: "sidenav.client-sdk", defaultMessage: "Client SDK"};
  let dataQuerying = {
    id: "sidenav.data-querying",
    defaultMessage: "Data Querying",
  };
  let devnet = {id: "sidenav.devnet", defaultMessage: "Devnet"};
  let foundationDelegation = {
    id: "sidenav.foundation-delegation",
    defaultMessage: "Foundation Delegation",
  };
  let hardFork = {id: "sidenav.hard-fork", defaultMessage: "Hard Fork"};
  let hotColdWallet = {
    id: "sidenav.hot-cold-wallets",
    defaultMessage: "Hot/Cold Wallets",
  };
  let ledgerHardWallet = {
    id: "sidenav.ledger-hardware-wallet",
    defaultMessage: "Ledger Hardware Wallet",
  };
  let seedPeers = {id: "sidenav.seed-peers", defaultMessage: "Seed Peers"};

  let stakingServiceGuidelines = {
    id: "sidenav.staking-service-guidelines",
    defaultMessage: "Staking Service Guidelines",
  };
  let developers = {id: "sidenav.developers", defaultMessage: "Developers"};
  let codebaseOverview = {
    id: "sidenav.codebase-overview",
    defaultMessage: "Codebase Overview",
  };
  let repoStructure = {
    id: "sidenav.repository-structure",
    defaultMessage: "Repository Structure",
  };
  let bip44Info = {
    id: "sidenav.BIP44-information",
    defaultMessage: "BIP44 Information",
  };
  let codeReviews = {
    id: "sidenav.code-reviews",
    defaultMessage: "Code Reviews",
  };
  let styleGuide = {id: "sidenav.style-guide", defaultMessage: "Style Guide"};
  let sandboxNode = {
    id: "sidenav.sandbox-node",
    defaultMessage: "Sandbox Node",
  };
  let graphqlAPI = {id: "sidenav.graphql-api", defaultMessage: "GraphQL API"};
  let logging = {id: "sidenav.logging", defaultMessage: "Logging"};
  let protocolArchitecture = {
    id: "sidenav.protocol-architecture",
    defaultMessage: "Protocol Architecture",
  };
  let lifecycleOfPayment = {
    id: "sidenav.lifecycle-of-a-payment",
    defaultMessage: "Lifecycle of a Payment",
  };
  let blockProducers = {
    id: "sidenav.block-producers",
    defaultMessage: "Block Producers",
  };
  let whatsInABlock = {
    id: "sidenav.whats-in-a-block",
    defaultMessage: "What's in a Block",
  };
  let consensus = {id: "sidenav.consensus", defaultMessage: "Consensus"};
  let proofOfStake = {
    id: "sidenav.proof-of-stake",
    defaultMessage: "Proof of Stake",
  };
  let snarkWorkers = {
    id: "sidenav.snark-workers",
    defaultMessage: "Snark Workers",
  };
  let scanState = {id: "sidenav.scan-state", defaultMessage: "Scan State"};
  let timeLockedAccounts = {
    id: "sidenav.time-locked-accounts",
    defaultMessage: "Time-locked Accounts",
  };
  let snapps = {id: "sidenav.snapps", defaultMessage: "Snapps"};
  let tokens = {id: "sidenav.tokens", defaultMessage: "Tokens"};
  let snarks = {id: "sidenav.snarks", defaultMessage: "SNARKs"};
  let gettingStartedUsingSnarks = {
    id: "sidenav.getting-starting-using-snarks",
    defaultMessage: "How Snapps Work",
  };
  let whichSnarkRightForMe = {
    id: "sidenav.which-snark-right-for-me",
    defaultMessage: "Which SNARK is right for me?",
  };
  let snarkyjsCryptoLibrary = {
    id: "sidenav.snarkyjs-crypto-library",
    defaultMessage: "The snarkyjs-crypto library",
  };
  let snarkyUniverseLibrary = {
    id: "sidenav.snarky-universe-library",
    defaultMessage: "The snarky-universe library",
  };
  let troubleshooting = {
    id: "sidenav.troubleshooting",
    defaultMessage: "Troubleshooting",
  };
  let glossary = {id: "sidenav.glossary", defaultMessage: "Glossary"};
  let faq = {id: "sidenav.faq", defaultMessage: "FAQ"};
  let exchangeFaq = {id: "sidenav.exchange-faq", defaultMessage: "Exchange FAQ"};
  let contributingToMina = {
    id: "sidenav.contributing-to-mina",
    defaultMessage: "Contributing to Mina",
  };
  let edit = {id: "sidenav.edit", defaultMessage: "Documentation"};
  let overview = {id: "sidenav.overview", defaultMessage: "Overview"};
  let documentation = {id: "sidenav.documentation", defaultMessage: "Edit"};
  let minaDocumentation = {
    id: "sidenav.mina-documentation",
    defaultMessage: "Mina Documentation",
  };
};

module SideNav = {
  module Styles = {
    open Css;
    let container =
      style([
        display(`none),
        media(
          Theme.MediaQuery.desktop,
          [
            position(`sticky),
            display(`block),
            top(`rem(2.)),
            height(`percent(100.)),
          ],
        ),
      ]);
  };

  [@react.component]
  let make = (~currentSlug) => {
    open ReactIntl;
    open Locale;
    open DocsNavsTranslations;
    module Item = SideNav.Item;
    module Section = SideNav.Section;
    let intl = ReactIntl.useIntl();

    let currentLanguageContext = Context.LanguageContext.useLanguageContext();
    let currentLanguage = currentLanguageContext.currentLanguage;
    let language = toISOCode(currentLanguage);
    let f = url => {j|/$(language)/$(url)|j};

    <div className=Styles.container>
      <SideNav currentSlug>
        <Item title={intl->Intl.formatMessage(minaOverview)} slug={f("/")} />
        <Item
          title={intl->Intl.formatMessage(gettingStarted)}
          slug={f("getting-started")}
        />
        <Section
          title={intl->Intl.formatMessage(usingMina)} slug={f("using-mina")}>
          <Item
            title={intl->Intl.formatMessage(keypairGeneration)}
            slug="keypair"
          />
          <Item
            title={intl->Intl.formatMessage(connectToNetwork)}
            slug="connecting"
          />
          <Item
            title={intl->Intl.formatMessage(sendPayment)}
            slug="send-payment"
          />
          <Item
            title={intl->Intl.formatMessage(stakingSnarking)}
            slug="staking"
          />
          <Item
            title={intl->Intl.formatMessage(cliReference)}
            slug="cli-reference"
          />
        </Section>
        <Section
          title={intl->Intl.formatMessage(advanced)} slug={f("advanced")}>
          <Item
            title={intl->Intl.formatMessage(archiveNode)}
            slug="archive-node"
          />
          <Item
            title={intl->Intl.formatMessage(archiveRedundancy)}
            slug="archive-redundancy"
          />
          <Item
            title={intl->Intl.formatMessage(blockProducerSidecar)}
            slug="bp-sidecar"
          />
          <Item
            title={intl->Intl.formatMessage(clientSDK)}
            slug="client-sdk"
          />
          <Item
            title={intl->Intl.formatMessage(dataQuerying)}
            slug="operating-for-data"
          />
          <Item
            title={intl->Intl.formatMessage(devnet)}
            slug="connecting-devnet"
          />
          <Item
            title={intl->Intl.formatMessage(foundationDelegation)}
            slug="foundation-delegation-program"
          />
          <Item title={intl->Intl.formatMessage(hardFork)} slug="hard-fork" />
          <Item
            title={intl->Intl.formatMessage(hotColdWallet)}
            slug="hot-cold-block-production"
          />
          <Item
            title={intl->Intl.formatMessage(ledgerHardWallet)}
            slug="ledger-app-mina"
          />
          <Item
            title={intl->Intl.formatMessage(seedPeers)}
            slug="seed-peers"
          />
          <Item
            title={intl->Intl.formatMessage(stakingServiceGuidelines)}
            slug="staking-service-guidelines"
          />
        </Section>
        <Section
          title={intl->Intl.formatMessage(developers)}
          slug={f("developers")}>
          <Item title={intl->Intl.formatMessage(overview)} slug="" />
          <Item
            title={intl->Intl.formatMessage(codebaseOverview)}
            slug="codebase-overview"
          />
          <Item
            title={intl->Intl.formatMessage(repoStructure)}
            slug="directory-structure"
          />
          <Item
            title={intl->Intl.formatMessage(bip44Info)}
            slug="bip44-information"
          />
          <Item
            title={intl->Intl.formatMessage(codeReviews)}
            slug="code-reviews"
          />
          <Item
            title={intl->Intl.formatMessage(styleGuide)}
            slug="style-guide"
          />
          <Item
            title={intl->Intl.formatMessage(sandboxNode)}
            slug="sandbox-node"
          />
          <Item
            title={intl->Intl.formatMessage(graphqlAPI)}
            slug="graphql-api"
          />
          <Item
            title={intl->Intl.formatMessage(clientSDK)}
            slug="client-sdk"
          />
          <Item title={intl->Intl.formatMessage(logging)} slug="logging" />
          <Item
            title={intl->Intl.formatMessage(contributingToMina)}
            slug="contributing"
          />
        </Section>
        <Section
          title={intl->Intl.formatMessage(protocolArchitecture)}
          slug={f("architecture")}>
          <Item title={intl->Intl.formatMessage(minaOverview)} slug="" />
          <Item
            title={intl->Intl.formatMessage(lifecycleOfPayment)}
            slug="lifecycle-payment"
          />
          <Item
            title={intl->Intl.formatMessage(blockProducers)}
            slug="block-producers"
          />
          <Item
            title={intl->Intl.formatMessage(whatsInABlock)}
            slug="whats-in-a-block"
          />
          <Item
            title={intl->Intl.formatMessage(consensus)}
            slug="consensus"
          />
          <Item
            title={intl->Intl.formatMessage(proofOfStake)}
            slug="proof-of-stake"
          />
          <Item
            title={intl->Intl.formatMessage(snarkWorkers)}
            slug="snark-workers"
          />
          <Item
            title={intl->Intl.formatMessage(scanState)}
            slug="scan-state"
          />
          <Item
            title={intl->Intl.formatMessage(timeLockedAccounts)}
            slug="timelock"
          />
          <Item title={intl->Intl.formatMessage(snapps)} slug="snapps" />
          <Item title={intl->Intl.formatMessage(tokens)} slug="tokens" />
        </Section>
        <Section title={intl->Intl.formatMessage(snarks)} slug={f("snarks")}>
          <Item title={intl->Intl.formatMessage(overview)} slug="" />
          <Item
            title={intl->Intl.formatMessage(gettingStartedUsingSnarks)}
            slug="snarky"
          />
          <Item
            title={intl->Intl.formatMessage(whichSnarkRightForMe)}
            slug="constructions"
          />
          <Item
            title={intl->Intl.formatMessage(snarkyjsCryptoLibrary)}
            slug="snarkyjs-crypto"
          />
          <Item
            title={intl->Intl.formatMessage(snarkyUniverseLibrary)}
            slug="snarky-universe"
          />
        </Section>
        <Item
          title={intl->Intl.formatMessage(troubleshooting)}
          slug={f("troubleshooting")}
        />
        <Item
          title={intl->Intl.formatMessage(glossary)}
          slug={f("glossary")}
        />
        <Item title={intl->Intl.formatMessage(faq)} slug={f("faq")} />
        <Item title={intl->Intl.formatMessage(exchangeFaq)} slug={f("exchange-faq")} />
      </SideNav>
    </div>;
  };
};

module Dropdown = {
  module Styles = {
    open Css;

    let dropdown =
      style([
        position(`sticky),
        display(`block),
        top(`rem(2.)),
        marginBottom(`rem(5.)),
        zIndex(Theme.StackingIndex.zNav),
        media(Theme.MediaQuery.desktop, [display(`none)]),
      ]);
  };

  [@react.component]
  let make = (~currentSlug) => {
    open Locale;
    open ReactIntl;
    open DocsNavsTranslations;
    module Item = DropdownNav.Item;
    module Section = DropdownNav.Section;
    let intl = ReactIntl.useIntl();
    let currentLanguageContext = Context.LanguageContext.useLanguageContext();
    let currentLanguage = currentLanguageContext.currentLanguage;
    let language = toISOCode(currentLanguage);
    let f = url => {j|/$(language)/$(url)|j};

    <div className=Styles.dropdown>
      <DropdownNav
        currentSlug defaultValue={intl->Intl.formatMessage(minaOverview)}>
        <Item title={intl->Intl.formatMessage(minaOverview)} slug={f("/")} />
        <Item
          title={intl->Intl.formatMessage(gettingStarted)}
          slug={f("getting-started")}
        />
        <Section
          title={intl->Intl.formatMessage(usingMina)} slug={f("using-mina")}>
          <Item
            title={intl->Intl.formatMessage(keypairGeneration)}
            slug="keypair"
          />
          <Item
            title={intl->Intl.formatMessage(connectToNetwork)}
            slug="connecting"
          />
          <Item
            title={intl->Intl.formatMessage(sendPayment)}
            slug="send-payment"
          />
          <Item
            title={intl->Intl.formatMessage(stakingSnarking)}
            slug="staking"
          />
          <Item
            title={intl->Intl.formatMessage(cliReference)}
            slug="cli-reference"
          />
        </Section>
        <Section
          title={intl->Intl.formatMessage(advanced)} slug={f("advanced")}>
          <Item
            title={intl->Intl.formatMessage(archiveNode)}
            slug="archive-node"
          />
          <Item
            title={intl->Intl.formatMessage(archiveRedundancy)}
            slug="archive-redundancy"
          />
          <Item
            title={intl->Intl.formatMessage(blockProducerSidecar)}
            slug="bp-sidecar"
          />
          <Item
            title={intl->Intl.formatMessage(clientSDK)}
            slug="client-sdk"
          />
          <Item
            title={intl->Intl.formatMessage(dataQuerying)}
            slug="operating-for-data"
          />
          <Item
            title={intl->Intl.formatMessage(devnet)}
            slug="connecting-devnet"
          />
          <Item
            title={intl->Intl.formatMessage(foundationDelegation)}
            slug="foundation-delegation-program"
          />
          <Item title={intl->Intl.formatMessage(hardFork)} slug="hard-fork" />
          <Item
            title={intl->Intl.formatMessage(hotColdWallet)}
            slug="hot-cold-block-production"
          />
          <Item
            title={intl->Intl.formatMessage(ledgerHardWallet)}
            slug="ledger-app-mina"
          />
          <Item
            title={intl->Intl.formatMessage(seedPeers)}
            slug="seed-peers"
          />
          <Item
            title={intl->Intl.formatMessage(stakingServiceGuidelines)}
            slug="staking-service-guidelines"
          />
        </Section>
        <Section
          title={intl->Intl.formatMessage(developers)}
          slug={f("developers")}>
          <Item title={intl->Intl.formatMessage(overview)} slug="" />
          <Item
            title={intl->Intl.formatMessage(codebaseOverview)}
            slug="codebase-overview"
          />
          <Item
            title={intl->Intl.formatMessage(repoStructure)}
            slug="directory-structure"
          />
          <Item
            title={intl->Intl.formatMessage(bip44Info)}
            slug="bip44-information"
          />
          <Item
            title={intl->Intl.formatMessage(codeReviews)}
            slug="code-reviews"
          />
          <Item
            title={intl->Intl.formatMessage(styleGuide)}
            slug="style-guide"
          />
          <Item
            title={intl->Intl.formatMessage(sandboxNode)}
            slug="sandbox-node"
          />
          <Item
            title={intl->Intl.formatMessage(graphqlAPI)}
            slug="graphql-api"
          />
          <Item
            title={intl->Intl.formatMessage(clientSDK)}
            slug="client-sdk"
          />
          <Item title={intl->Intl.formatMessage(logging)} slug="logging" />
          <Item
            title={intl->Intl.formatMessage(contributingToMina)}
            slug="contributing"
          />
        </Section>
        <Section
          title={intl->Intl.formatMessage(protocolArchitecture)}
          slug={f("architecture")}>
          <Item title={intl->Intl.formatMessage(minaOverview)} slug="" />
          <Item
            title={intl->Intl.formatMessage(lifecycleOfPayment)}
            slug="lifecycle-payment"
          />
          <Item
            title={intl->Intl.formatMessage(blockProducers)}
            slug="block-producers"
          />
          <Item
            title={intl->Intl.formatMessage(whatsInABlock)}
            slug="whats-in-a-block"
          />
          <Item
            title={intl->Intl.formatMessage(consensus)}
            slug="consensus"
          />
          <Item
            title={intl->Intl.formatMessage(proofOfStake)}
            slug="proof-of-stake"
          />
          <Item
            title={intl->Intl.formatMessage(snarkWorkers)}
            slug="snark-workers"
          />
          <Item
            title={intl->Intl.formatMessage(scanState)}
            slug="scan-state"
          />
          <Item
            title={intl->Intl.formatMessage(timeLockedAccounts)}
            slug="timelock"
          />
          <Item title={intl->Intl.formatMessage(snapps)} slug="snapps" />
          <Item title={intl->Intl.formatMessage(tokens)} slug="tokens" />
        </Section>
        <Section title={intl->Intl.formatMessage(snarks)} slug={f("snarks")}>
          <Item title={intl->Intl.formatMessage(overview)} slug="" />
          <Item
            title={intl->Intl.formatMessage(gettingStartedUsingSnarks)}
            slug="snarky"
          />
          <Item
            title={intl->Intl.formatMessage(whichSnarkRightForMe)}
            slug="constructions"
          />
          <Item
            title={intl->Intl.formatMessage(snarkyjsCryptoLibrary)}
            slug="snarkyjs-crypto"
          />
          <Item
            title={intl->Intl.formatMessage(snarkyUniverseLibrary)}
            slug="snarky-universe"
          />
        </Section>
        <Item
          title={intl->Intl.formatMessage(troubleshooting)}
          slug={f("troubleshooting")}
        />
        <Item
          title={intl->Intl.formatMessage(glossary)}
          slug={f("glossary")}
        />
        <Item title={intl->Intl.formatMessage(faq)} slug={f("faq")} />
        <Item title={intl->Intl.formatMessage(exchangeFaq)} slug={f("exchange-faq")} />
      </DropdownNav>
    </div>;
  };
};
