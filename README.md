_Note: This repo contains the *old* docs website. The new docs website is located at https://github.com/o1-labs/docs2_


<img src="https://github.com/MinaProtocol/docs/blob/main/public/static/img/svg/mina-wordmark-redviolet.svg" width="350" alt="Mina logo">

# Mina Docs

To view this website, visit [docs.minaprotocol.com](https://docs.minaprotocol.com/).

## Contributing

Click the `Suggest changes` button at the top right of any page on [the docs website](https://docs.minaprotocol.com/) to edit that page and submit a pull request via Github.

## How to run (for devs)

This website is built with NextJS & Contentful. Any commit to the `main` branch will be built and deployed automatically.

To run locally, first make sure you have `git lfs` installed.

On Mac run:

```bash
brew install git-lfs
```

After that you have to install `git-lfs` in the website directory and pull it.

```bash
git lfs install
git lfs pull
```

Install it and run:

```bash
npm install
npm run dev
```

Build and run:

```bash
npm run build
npm run start
```

### Recommendation:

Run BuckleScript build system `bsb -w` and `next -w` separately. For the sake
of simple convention, `npm run dev` run both `bsb` and `next` concurrently.
However, this doesn't offer the full [colorful and nice
error
output](https://reasonml.github.io/blog/2017/08/25/way-nicer-error-messages.html)
experience that ReasonML can offer, don't miss it!

There are 2 convenience scripts to facilitate running these separate processes:

1. `npm run dev:reason` - This script will start the ReasonML toolchain in
   watch mode to re-compile whenever you make changes.
2. `npm run dev:next` - This script will start the next.js development server
   so that you will be able to access your site at the location output by the
   script. This will also hot reload as you make changes.

You should start the scripts in the presented order.
