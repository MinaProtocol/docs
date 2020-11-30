# Hubspot Subscription

A serverless application that registers an email with our Hubspot service.

### Prerequisites

Expects that the PORTALID and FORMID environment variable is set. These correspond to the specific Hubsport newsletter form.

## Deployment

To deploy, you must have serverless installed.

```
  $ npm install -g serverless
```

Then provide the appropriate credentials.

```
  $ serverless config credentials --provider aws --key <YOUR-ACCESS-KEY> --secret <YOUR-SECRET-KEY>
```

Once configured, we can deploy.

```
  $ serverless deploy
```

## Built With

- [Serverless](https://www.serverless.com/framework/docs/)
- [Axios](https://github.com/axios/axios)
