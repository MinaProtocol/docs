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
        </Head>
        <body style={{ margin: 0 + "px" }}>
          <Main />
          <NextScript />
        </body>
      </Html>
    );
  }
}
