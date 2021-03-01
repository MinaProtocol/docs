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
    module Item = SideNav.Item;
    module Section = SideNav.Section;
    let f = s => "/docs/" ++ s;
    <div className=Styles.container>
      <SideNav currentSlug>
        <Item title="Mina Overview" slug={f("")} />
        <Section title="Getting Started" slug={f("getting-started")}>
          <Item title="Installation" slug="" />
          <Item title="Keypair Generation" slug="keypair" />
          <Item title="mina-generate-keypair" slug="mina-generate-keypair" />
          <Item title="Connect to the Network" slug="connecting" />
          <Item title="Staking & Snarking" slug="staking" />
          <Item title="Troubleshooting" slug="troubleshooting" />
        </Section>
        <Section title="Advanced" slug={f("advanced")}>
          <Item title="Hard Fork" slug="hard-fork" />
          <Item title="Archive Node" slug="archive-node" />
          <Item title="Archive Redundancy" slug="archive-redundancy" />
          <Item
            title="Staking Service Guidelines"
            slug="staking-service-guidelines"
          />
          <Item title="client-sdk" slug="client-sdk" />
          <Item title="ledger-app-mina" slug="ledger-app-mina" />
          <Item
            title="Data Querying for Node Operators"
            slug="operating-for-data"
          />
          <Item
            title="Hot/Cold Secure Block Production"
            slug="hot-cold-block-production"
          />
          <Item title="Devnet" slug="connecting-devnet" />
        </Section>
        <Section title="Developers" slug={f("developers")}>
          <Item title="Developers Overview" slug="" />
          <Item title="Codebase Overview" slug="codebase-overview" />
          <Item title="Repository Structure" slug="directory-structure" />
          <Item title="BIP44 Information" slug="bip44-information" />
          <Item title="Code Reviews" slug="code-reviews" />
          <Item title="Style Guide" slug="style-guide" />
          <Item title="Sandbox Node" slug="sandbox-node" />
          <Item title="GraphQL API" slug="graphql-api" />
          <Item title="Client SDK" slug="client-sdk" />
          <Item title="Logging" slug="logging" />
          <Item title="Contributing to Mina" slug="contributing" />
        </Section>
        <Section title="Protocol Architecture" slug={f("architecture")}>
          <Item title="Mina Overview" slug="" />
          <Item title="Lifecycle of a Payment" slug="lifecycle-payment" />
          <Item title="Block Producers" slug="block-producers" />
          <Item title="Consensus" slug="consensus" />
          <Item title="Proof of Stake" slug="proof-of-stake" />
          <Item title="Snark Workers" slug="snark-workers" />
          <Item title="Scan State" slug="scan-state" />
          <Item title="Time-locked Accounts" slug="timelock" />
          <Item title="Snapps" slug="snapps" />
          <Item title="Tokens" slug="tokens" />
          <Item title="SNARKs Overview" slug="" />
          <Item title="Getting started using SNARKs" slug="snarky" />
          <Item title="Which SNARK is right for me?" slug="constructions" />
          <Item title="The snarkyjs-crypto library" slug="snarkyjs-crypto" />
          <Item title="The snarky-universe library" slug="snarky-universe" />
        </Section>
        <Item title="CLI Reference" slug={f("cli-reference")} />
        <Item title="Glossary" slug={f("glossary")} />
        <Item title="FAQ" slug={f("faq")} />
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
    module Item = DropdownNav.Item;
    module Section = DropdownNav.Section;
    let f = s => "/docs/" ++ s;
    let getCurrentValue = s => {
      Js.String.match([%re "/(\/docs\/)(.*)/"], s)
      ->Belt.Option.mapWithDefault("Documentation", match => {
          switch (match[2]) {
          | "getting-started" => "Getting Started"
          | "my-first-transaction" => "My First Transaction"
          | "node-operator" => "Become a Node Operator"
          | "contributing" => "Contributing to Mina"

          | "connecting" => "Connecting Overview"
          | "connecting/connecting-zenith" => "Connecting To Zenith"
          | "connecting/connecting-devnet" => "Connecting To Devnet"

          | "developers" => "Developers Overview"
          | "developers/snarkyjs-crypto" => "Codebase Overview"
          | "developers/codebase-overview" => "Codebase Overview"
          | "developers/directory-structure" => "Repository Structure"
          | "developers/code-reviews" => "Code Reviews"
          | "developers/style-guide" => "Style Guide"
          | "developers/sandbox-node" => "Sandbox Node"
          | "developers/graphql-api" => "GraphQL API"
          | "developers/client-sdk" => "Client SDK"
          | "developers/logging" => "Logging"

          | "keypair" => "Keypair Overview"
          | "keypair/mina-generate-keypair" => "mina-generate-keypair"
          | "keypair/ledger-app-mina" => "ledger-app-mina"
          | "keypair/client-sdk" => "client-sdk"

          | "architecture" => "Mina Overview"
          | "architecture/lifecycle-payment" => "Lifecycle of a Payment"
          | "architecture/block-producers" => "Block Producers"
          | "architecture/consensus" => "Consensus"
          | "architecture/proof-of-stake" => "Proof of Stake"
          | "architecture/snark-workers" => "Snark Workers"
          | "architecture/scan-state" => "Scan State"

          | "snarks" => "SNARKs Overview"
          | "snarks/snarky" => "Getting started using SNARKs"
          | "snarks/constructions" => "Which SNARK is right for me?"
          | "snarks/snarkyjs-crypto" => "The snarkyjs-crypto library"
          | "snarks/snarky-universe" => "The snarky-universe library"

          | "snapps" => "Snapps"
          | "cli-reference" => "CLI Reference"
          | "tokens" => "Tokens"
          | "troubleshooting" => "FAQ"
          | "glossary" => "Glossary"

          | _ => "Documentation"
          }
        });
    };

    <div className=Styles.dropdown>
      <DropdownNav currentSlug defaultValue={getCurrentValue(currentSlug)}>
        <Item title="Mina Overview" slug={f("/")} />
        <Section title="Getting Started" slug={f("getting-started")}>
          <Item title="Installation" slug="" />
          <Item title="Keypair Generation" slug="keypair" />
          <Item title="mina-generate-keypair" slug="mina-generate-keypair" />
          <Item title="Connect to the Network" slug="connecting" />
          <Item title="Staking & Snarking" slug="staking" />
          <Item title="Troubleshooting" slug="troubleshooting" />
        </Section>
        <Section title="Advanced" slug={f("advanced")}>
          <Item title="Hard Fork" slug="hard-fork" />
          <Item title="Archive Node" slug="archive-node" />
          <Item title="Archive Redundancy" slug="archive-redundancy" />
          <Item
            title="Staking Service Guidelines"
            slug="staking-service-guidelines"
          />
          <Item title="client-sdk" slug="client-sdk" />
          <Item title="ledger-app-mina" slug="ledger-app-mina" />
          <Item
            title="Data Querying for Node Operators"
            slug="operating-for-data"
          />
          <Item
            title="Hot/Cold Secure Block Production"
            slug="hot-cold-block-production"
          />
          <Item title="Devnet" slug="connecting-devnet" />
        </Section>
        <Section title="Developers" slug={f("developers")}>
          <Item title="Developers Overview" slug="" />
          <Item title="Codebase Overview" slug="codebase-overview" />
          <Item title="Repository Structure" slug="directory-structure" />
          <Item title="BIP44 Information" slug="bip44-information" />
          <Item title="Code Reviews" slug="code-reviews" />
          <Item title="Style Guide" slug="style-guide" />
          <Item title="Sandbox Node" slug="sandbox-node" />
          <Item title="GraphQL API" slug="graphql-api" />
          <Item title="Client SDK" slug="client-sdk" />
          <Item title="Logging" slug="logging" />
          <Item title="Contributing to Mina" slug="contributing" />
        </Section>
        <Section title="Protocol Architecture" slug={f("architecture")}>
          <Item title="Mina Overview" slug="" />
          <Item title="Lifecycle of a Payment" slug="lifecycle-payment" />
          <Item title="Block Producers" slug="block-producers" />
          <Item title="Consensus" slug="consensus" />
          <Item title="Proof of Stake" slug="proof-of-stake" />
          <Item title="Snark Workers" slug="snark-workers" />
          <Item title="Scan State" slug="scan-state" />
          <Item title="Time-locked Accounts" slug="timelock" />
          <Item title="Snapps" slug="snapps" />
          <Item title="Tokens" slug="tokens" />
          <Item title="SNARKs Overview" slug="" />
          <Item title="Getting started using SNARKs" slug="snarky" />
          <Item title="Which SNARK is right for me?" slug="constructions" />
          <Item title="The snarkyjs-crypto library" slug="snarkyjs-crypto" />
          <Item title="The snarky-universe library" slug="snarky-universe" />
        </Section>
        <Item title="CLI Reference" slug={f("cli-reference")} />
        <Item title="Glossary" slug={f("glossary")} />
        <Item title="FAQ" slug={f("faq")} />
      </DropdownNav>
    </div>;
  };
};
