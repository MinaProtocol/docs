const path = require("path");

const withMDX = require("@next/mdx")({
  options: {
    remarkPlugins: [require("remark-slug"), require("remark-math")],
    rehypePlugins: [
      require("rehype-katex"),
      [require("rehype-highlight"), { subset: false }],
    ],
  },
});

const withTM = require("next-transpile-modules")([
  "bs-platform",
  "bs-css",
  "bsc-stdlib-polyfill",
  "bs-fetch",
]);

const withBundleAnalyzer = require("@next/bundle-analyzer")({
  enabled: process.env.ANALYZE === "true",
});

const GOOGLE_API_KEY =
  process.env.GOOGLE_API_KEY || "AIzaSyDIFwMr7SPGCLl_o6e4UZKi1q9l8snkUZs";

module.exports = withTM(
  withBundleAnalyzer(
    withMDX({
      async exportPathMap(pages) {
        return pages;
      },
      pageExtensions: ["jsx", "js", "mdx"],
      webpack(config, options) {
        config.resolve.alias["@reason"] = path.join(
          __dirname,
          "lib",
          "es6",
          "src"
        );
        config.resolve.extensions.push(".bs.js");
        return config;
      },
      env: {
        GOOGLE_API_KEY: GOOGLE_API_KEY,
      },
    })
  )
);
