import { useEffect } from 'react';

export default function Index() {
  useEffect(() => {
    const language = "en" // Only show English docs
    document.location.href = '/' + language;
  });

  return (<p> </p>);
};
