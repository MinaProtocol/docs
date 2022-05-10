import Document, { Html, Head, Main, NextScript } from "next/document";
import { extractCritical } from "emotion-server";

const globalStyles = {
  scrollPaddingTop: "6rem",
  fontFamily: "Monument Grotesk, serif",
  fontSize: "16px",
  lineHeight: "29px",
};

export default class MyDocument extends Document {
  static getInitialProps({ renderPage }) {
    const page = renderPage();
    const styles = extractCritical(page.html);
    return { ...page, ...styles };
  }

  constructor(props) {
    super(props);
    const { __NEXT_DATA__, ids } = props;
    if (ids) {
      __NEXT_DATA__.ids = ids;
    }
  }

  render() {
    return (
      <Html style={globalStyles}>
        <Head>
          <style dangerouslySetInnerHTML={{ __html: this.props.css }} />
          <script
            dangerouslySetInnerHTML={{
              __html: `(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
              new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
              j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
              'https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
              })(window,document,'script','dataLayer','GTM-KCQRV4Z');`,
            }}
          ></script>
        </Head>
        <body style={{ margin: 0 + "px" }}>
          <noscript
            dangerouslySetInnerHTML={{
              __html: `<iframe src="https://www.googletagmanager.com/ns.html?id=GTM-KCQRV4Z"
              height="0" width="0" style="display:none;visibility:hidden"></iframe>`,
            }}
          ></noscript>
          <Main />
          <NextScript />
        </body>
      </Html>
    );
  }
}
