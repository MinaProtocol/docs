module SideNav = {
  module Styles = {
    open Css;
    let container =
      style([
        display(`none),
        media(Theme.MediaQuery.desktop, [display(`block)]),
      ]);
  };

  [@react.component]
  let make = (~currentSlug) => {
    open Context.LanguageContext;
    open Translations;
    module Item = SideNav.Item;
    module Section = SideNav.Section;
    let currentLanguageContext = useLanguageContext();
    let currentLanguage = currentLanguageContext.currentLanguage;
    let language = toISOCode(currentLanguage);
    let f = url => {j|/$(language)/$(url)|j};

    <div className=Styles.container>
      <SideNav currentSlug>
        <Item
          title={translate(currentLanguage, "Mina Overview")}
          slug={f("/")}
        />
        <Item
          title={translate(currentLanguage, "Getting Started")}
          slug={f("getting-started")}
        />
        <Section
          title={translate(currentLanguage, "Using Mina")}
          slug={f("using-mina")}>
          <Item
            title={translate(currentLanguage, "Keypair Generation")}
            slug="keypair"
          />
          <Item
            title={translate(currentLanguage, "Connect to the Network")}
            slug="connecting"
          />
          <Item
            title={translate(currentLanguage, "Sending a Payment")}
            slug="send-payment"
          />
          <Item
            title={translate(currentLanguage, "Staking & Snarking")}
            slug="staking"
          />
          <Item
            title={translate(currentLanguage, "CLI Reference")}
            slug="cli-reference"
          />
        </Section>
        <Section
          title={translate(currentLanguage, "Advanced")}
          slug={f("advanced")}>
          <Item
            title={translate(currentLanguage, "Archive Node")}
            slug="archive-node"
          />
          <Item
            title={translate(currentLanguage, "Archive Redundancy")}
            slug="archive-redundancy"
          />
          <Item
            title={translate(currentLanguage, "Block Producer Sidecar")}
            slug="bp-sidecar"
          />
          <Item
            title={translate(currentLanguage, "Client SDK")}
            slug="client-sdk"
          />
          <Item
            title={translate(currentLanguage, "Data Querying")}
            slug="operating-for-data"
          />
          <Item
            title={translate(currentLanguage, "Devnet")}
            slug="connecting-devnet"
          />
          <Item
            title={translate(currentLanguage, "Foundation Delegation")}
            slug="foundation-delegation-program"
          />
          <Item
            title={translate(currentLanguage, "Hard Fork")}
            slug="hard-fork"
          />
          <Item
            title={translate(currentLanguage, "Hot/Cold Wallets")}
            slug="hot-cold-block-production"
          />
          <Item
            title={translate(currentLanguage, "Ledger Hardware Wallet")}
            slug="ledger-app-mina"
          />
          <Item
            title={translate(currentLanguage, "Seed Peers")}
            slug="seed-peers"
          />
          <Item
            title={translate(currentLanguage, "Staking Service Guidelines")}
            slug="staking-service-guidelines"
          />
        </Section>
        <Section
          title={translate(currentLanguage, "Developers")}
          slug={f("developers")}>
          <Item title={translate(currentLanguage, "Overview")} slug="" />
          <Item
            title={translate(currentLanguage, "Codebase Overview")}
            slug="codebase-overview"
          />
          <Item
            title={translate(currentLanguage, "Repository Structure")}
            slug="directory-structure"
          />
          <Item
            title={translate(currentLanguage, "BIP44 Information")}
            slug="bip44-information"
          />
          <Item
            title={translate(currentLanguage, "Code Reviews")}
            slug="code-reviews"
          />
          <Item
            title={translate(currentLanguage, "Style Guide")}
            slug="style-guide"
          />
          <Item
            title={translate(currentLanguage, "Sandbox Node")}
            slug="sandbox-node"
          />
          <Item
            title={translate(currentLanguage, "GraphQL API")}
            slug="graphql-api"
          />
          <Item
            title={translate(currentLanguage, "Client SDK")}
            slug="client-sdk"
          />
          <Item
            title={translate(currentLanguage, "Logging")}
            slug="logging"
          />
          <Item
            title={translate(currentLanguage, "Contributing to Mina")}
            slug="contributing"
          />
        </Section>
        <Section
          title={translate(currentLanguage, "Protocol Architecture")}
          slug={f("architecture")}>
          <Item title={translate(currentLanguage, "Mina Overview")} slug="" />
          <Item
            title={translate(currentLanguage, "Lifecycle of a Payment")}
            slug="lifecycle-payment"
          />
          <Item
            title={translate(currentLanguage, "Block Producers")}
            slug="block-producers"
          />
          <Item
            title={translate(currentLanguage, "What's in a Block")}
            slug="whats-in-a-block"
          />
          <Item
            title={translate(currentLanguage, "Consensus")}
            slug="consensus"
          />
          <Item
            title={translate(currentLanguage, "Proof of Stake")}
            slug="proof-of-stake"
          />
          <Item
            title={translate(currentLanguage, "Snark Workers")}
            slug="snark-workers"
          />
          <Item
            title={translate(currentLanguage, "Scan State")}
            slug="scan-state"
          />
          <Item
            title={translate(currentLanguage, "Time-locked Accounts")}
            slug="timelock"
          />
          <Item title={translate(currentLanguage, "Snapps")} slug="snapps" />
          <Item title={translate(currentLanguage, "Tokens")} slug="tokens" />
        </Section>
        <Section
          title={translate(currentLanguage, "SNARKs")} slug={f("snarks")}>
          <Item title={translate(currentLanguage, "Overview")} slug="" />
          <Item
            title={translate(currentLanguage, "Getting started using SNARKs")}
            slug="snarky"
          />
          <Item
            title={translate(currentLanguage, "Which SNARK is right for me?")}
            slug="constructions"
          />
          <Item
            title={translate(currentLanguage, "The snarkyjs-crypto library")}
            slug="snarkyjs-crypto"
          />
          <Item
            title={translate(currentLanguage, "The snarky-universe library")}
            slug="snarky-universe"
          />
        </Section>
        <Item
          title={translate(currentLanguage, "Troubleshooting")}
          slug={f("troubleshooting")}
        />
        <Item
          title={translate(currentLanguage, "Glossary")}
          slug={f("glossary")}
        />
        <Item title={translate(currentLanguage, "FAQ")} slug={f("faq")} />
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
    open Context.LanguageContext;
    open Translations;
    module Item = DropdownNav.Item;
    module Section = DropdownNav.Section;
    let currentLanguageContext = useLanguageContext();
    let currentLanguage = currentLanguageContext.currentLanguage;
    let language = toISOCode(currentLanguage);
    let f = url => {j|/$(language)/$(url)|j};

    <div className=Styles.dropdown>
      <DropdownNav
        currentSlug
        defaultValue={translate(currentLanguage, "Mina Documentation")}>
        <Item
          title={translate(currentLanguage, "Mina Overview")}
          slug={f("/")}
        />
        <Item
          title={translate(currentLanguage, "Getting Started")}
          slug={f("getting-started")}
        />
        <Section
          title={translate(currentLanguage, "Using Mina")}
          slug={f("using-mina")}>
          <Item
            title={translate(currentLanguage, "Keypair Generation")}
            slug="keypair"
          />
          <Item
            title={translate(currentLanguage, "Connect to the Network")}
            slug="connecting"
          />
          <Item
            title={translate(currentLanguage, "Sending a Payment")}
            slug="send-payment"
          />
          <Item
            title={translate(currentLanguage, "Staking & Snarking")}
            slug="staking"
          />
          <Item
            title={translate(currentLanguage, "CLI Reference")}
            slug="cli-reference"
          />
        </Section>
        <Section
          title={translate(currentLanguage, "Advanced")}
          slug={f("advanced")}>
          <Item
            title={translate(currentLanguage, "Archive Node")}
            slug="archive-node"
          />
          <Item
            title={translate(currentLanguage, "Archive Redundancy")}
            slug="archive-redundancy"
          />
          <Item
            title={translate(currentLanguage, "Block Producer Sidecar")}
            slug="bp-sidecar"
          />
          <Item
            title={translate(currentLanguage, "Client SDK")}
            slug="client-sdk"
          />
          <Item
            title={translate(currentLanguage, "Data Querying")}
            slug="operating-for-data"
          />
          <Item
            title={translate(currentLanguage, "Devnet")}
            slug="connecting-devnet"
          />
          <Item
            title={translate(currentLanguage, "Foundation Delegation")}
            slug="foundation-delegation-program"
          />
          <Item
            title={translate(currentLanguage, "Hard Fork")}
            slug="hard-fork"
          />
          <Item
            title={translate(currentLanguage, "Hot/Cold Wallets")}
            slug="hot-cold-block-production"
          />
          <Item
            title={translate(currentLanguage, "Ledger Hardware Wallet")}
            slug="ledger-app-mina"
          />
          <Item
            title={translate(currentLanguage, "Seed Peers")}
            slug="seed-peers"
          />
          <Item
            title={translate(currentLanguage, "Staking Service Guidelines")}
            slug="staking-service-guidelines"
          />
        </Section>
        <Section
          title={translate(currentLanguage, "Developers")}
          slug={f("developers")}>
          <Item title={translate(currentLanguage, "Overview")} slug="" />
          <Item
            title={translate(currentLanguage, "Codebase Overview")}
            slug="codebase-overview"
          />
          <Item
            title={translate(currentLanguage, "Repository Structure")}
            slug="directory-structure"
          />
          <Item
            title={translate(currentLanguage, "BIP44 Information")}
            slug="bip44-information"
          />
          <Item
            title={translate(currentLanguage, "Code Reviews")}
            slug="code-reviews"
          />
          <Item
            title={translate(currentLanguage, "Style Guide")}
            slug="style-guide"
          />
          <Item
            title={translate(currentLanguage, "Sandbox Node")}
            slug="sandbox-node"
          />
          <Item
            title={translate(currentLanguage, "GraphQL API")}
            slug="graphql-api"
          />
          <Item
            title={translate(currentLanguage, "Client SDK")}
            slug="client-sdk"
          />
          <Item
            title={translate(currentLanguage, "Logging")}
            slug="logging"
          />
          <Item
            title={translate(currentLanguage, "Contributing to Mina")}
            slug="contributing"
          />
        </Section>
        <Section
          title={translate(currentLanguage, "Protocol Architecture")}
          slug={f("architecture")}>
          <Item title={translate(currentLanguage, "Mina Overview")} slug="" />
          <Item
            title={translate(currentLanguage, "Lifecycle of a Payment")}
            slug="lifecycle-payment"
          />
          <Item
            title={translate(currentLanguage, "Block Producers")}
            slug="block-producers"
          />
          <Item
            title={translate(currentLanguage, "What's in a Block")}
            slug="whats-in-a-block"
          />
          <Item
            title={translate(currentLanguage, "Consensus")}
            slug="consensus"
          />
          <Item
            title={translate(currentLanguage, "Proof of Stake")}
            slug="proof-of-stake"
          />
          <Item
            title={translate(currentLanguage, "Snark Workers")}
            slug="snark-workers"
          />
          <Item
            title={translate(currentLanguage, "Scan State")}
            slug="scan-state"
          />
          <Item
            title={translate(currentLanguage, "Time-locked Accounts")}
            slug="timelock"
          />
          <Item title={translate(currentLanguage, "Snapps")} slug="snapps" />
          <Item title={translate(currentLanguage, "Tokens")} slug="tokens" />
        </Section>
        <Section
          title={translate(currentLanguage, "SNARKs")} slug={f("snarks")}>
          <Item title={translate(currentLanguage, "Overview")} slug="" />
          <Item
            title={translate(currentLanguage, "Getting started using SNARKs")}
            slug="snarky"
          />
          <Item
            title={translate(currentLanguage, "Which SNARK is right for me?")}
            slug="constructions"
          />
          <Item
            title={translate(currentLanguage, "The snarkyjs-crypto library")}
            slug="snarkyjs-crypto"
          />
          <Item
            title={translate(currentLanguage, "The snarky-universe library")}
            slug="snarky-universe"
          />
        </Section>
        <Item
          title={translate(currentLanguage, "Troubleshooting")}
          slug={f("troubleshooting")}
        />
        <Item
          title={translate(currentLanguage, "Glossary")}
          slug={f("glossary")}
        />
        <Item title={translate(currentLanguage, "FAQ")} slug={f("faq")} />
      </DropdownNav>
    </div>;
  };
};
