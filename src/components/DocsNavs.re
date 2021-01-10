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
        <Item title="Overview" slug="/docs" />
        <Item title="Getting Started" slug={f("getting-started")} />
        <Section title="Generate a Keypair" slug={f("keypair")}>
          <Item title="Keypair Overview" slug="" />
          <Item title="mina-generate-keypair" slug="mina-generate-keypair" />
          <Item title="ledger-app-mina" slug="ledger-app-mina" />
        </Section>
        //<Item title="Generate a Keypair" slug={f("keypair")} />
        <Item title="Connect to the Network" slug={f("connecting")} />
        <Item title="Tips for Node Operators" slug={f("node-operator")} />
        <Item title="Hard Fork" slug={f("hard-fork")} />
        <Section title="Developers" slug={f("developers")}>
          <Item title="Developers Overview" slug="" />
          <Item title="Codebase Overview" slug="codebase-overview" />
          <Item title="Repository Structure" slug="directory-structure" />
          <Item title="Code Reviews" slug="code-reviews" />
          <Item title="Style Guide" slug="style-guide" />
          <Item title="Sandbox Node" slug="sandbox-node" />
          <Item title="GraphQL API" slug="graphql-api" />
          <Item title="Logging" slug="logging" />
        </Section>
        <Section title="Protocol Architecture" slug={f("architecture")}>
          <Item title="Mina Overview" slug="" />
          <Item title="Lifecycle of a Payment" slug="lifecycle-payment" />
          <Item title="Block Producers" slug="block-producers" />
          <Item title="Consensus" slug="consensus" />
          <Item title="Proof of Stake" slug="proof-of-stake" />
          <Item title="Snark Workers" slug="snark-workers" />
          <Item title="Time-locked Accounts" slug="timelock" />
          <Item title="Snapps" slug="snapps" />
          <Item title="Tokens" slug="tokens" />
        </Section>
        <Section title="SNARKs" slug={f("snarks")}>
          <Item title="SNARKs Overview" slug="" />
          <Item title="Getting started using SNARKs" slug="snarky" />
          <Item title="Which SNARK is right for me?" slug="constructions" />
          <Item title="The snarkyjs-crypto library" slug="snarkyjs-crypto" />
          <Item title="The snarky-universe library" slug="snarky-universe" />
        </Section>
        <Item title="Contributing to Mina" slug={f("contributing")} />
        //<Item title="CLI Reference" slug={f("cli-reference")} />
        <Item title="Troubleshooting" slug={f("troubleshooting")} />
        <Item title="FAQ" slug={f("faq")} />
        <Item title="Glossary" slug={f("glossary")} />
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

          | "developers" => "Developers Overview"
          | "developers/snarkyjs-crypto" => "Codebase Overview"
          | "developers/codebase-overview" => "Codebase Overview"
          | "developers/directory-structure" => "Repository Structure"
          | "developers/code-reviews" => "Code Reviews"
          | "developers/style-guide" => "Style Guide"
          | "developers/sandbox-node" => "Sandbox Node"
          | "developers/graphql-api" => "GraphQL API"
          | "developers/logging" => "Logging"

          | "architecture" => "Mina Overview"
          | "architecture/lifecycle-payment" => "Lifecycle of a Payment"
          | "architecture/block-producers" => "Block Producers"
          | "architecture/consensus" => "Consensus"
          | "architecture/proof-of-stake" => "Proof of Stake"
          | "architecture/snark-workers" => "Snark Workers"

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
        <Item title="Overview" slug="/docs" />
        <Item title="Getting Started" slug={f("getting-started")} />
        <Item title="Generate a Keypair" slug={f("keypair")} />
        <Item title="Connect to the Network" slug={f("connecting")} />
        <Item title="Tips for Node Operators" slug={f("node-operator")} />
        <Item title="Hard Fork" slug={f("hard-fork")} />
        <Section title="Developers" slug={f("developers")}>
          <Item title="Developers Overview" slug="" />
          <Item title="Codebase Overview" slug="codebase-overview" />
          <Item title="Repository Structure" slug="directory-structure" />
          <Item title="Code Reviews" slug="code-reviews" />
          <Item title="Style Guide" slug="style-guide" />
          <Item title="Sandbox Node" slug="sandbox-node" />
          <Item title="GraphQL API" slug="graphql-api" />
          <Item title="Logging" slug="logging" />
        </Section>
        <Section title="Protocol Architecture" slug={f("architecture")}>
          <Item title="Mina Overview" slug="" />
          <Item title="Lifecycle of a Payment" slug="lifecycle-payment" />
          <Item title="Block Producers" slug="block-producers" />
          <Item title="Consensus" slug="consensus" />
          <Item title="Proof of Stake" slug="proof-of-stake" />
          <Item title="Snark Workers" slug="snark-workers" />
          <Item title="Time-locked Accounts" slug="timelock" />
          <Item title="Snapps" slug="snapps" />
          <Item title="Tokens" slug="tokens" />
        </Section>
        <Section title="SNARKs" slug={f("snarks")}>
          <Item title="SNARKs Overview" slug="" />
          <Item title="Getting started using SNARKs" slug="snarky" />
          <Item title="Which SNARK is right for me?" slug="constructions" />
          <Item title="The snarkyjs-crypto library" slug="snarkyjs-crypto" />
          <Item title="The snarky-universe library" slug="snarky-universe" />
        </Section>
        <Item title="Contributing to Mina" slug={f("contributing")} />
        //<Item title="CLI Reference" slug={f("cli-reference")} />
        <Item title="Troubleshooting" slug={f("troubleshooting")} />
        <Item title="FAQ" slug={f("faq")} />
        <Item title="Glossary" slug={f("glossary")} />
      </DropdownNav>
    </div>;
  };
};
