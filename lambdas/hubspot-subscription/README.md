# Hubspot Subscription

A serverless application that registers an email with our Hubspot service.

### Prerequisites

Expects that the HUBSPOT_API_KEY environment variable is set.

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
- [Hubspot API](https://github.com/HubSpot/hubspot-api-nodejs)
