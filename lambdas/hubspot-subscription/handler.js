"use strict";

const qs = require("querystring");
const hubspot = require("@hubspot/api-client");

const { HUBSPOT_API_KEY } = process.env;
const hubspotClient = new hubspot.Client({ apiKey: HUBSPOT_API_KEY });

module.exports.sendConfirmation = async (event) => {
  if (event.httpMethod !== "POST" || !event.body) {
    return {
      statusCode: 400,
      body: "No email address was provided.",
      headers: {
        "Access-Control-Allow-Origin": "*",
        "Access-Control-Allow-Headers": "Content-Type",
      },
    };
  }

  const data = qs.parse(event.body);
  const payload = { properties: { email: data.email } };

  try {
    await hubspotClient.crm.contacts.basicApi.create(payload);
  } catch (e) {
    let body = "";

    // Email already exists
    if (e.body.status === "error" && e.body.category === "CONFLICT") {
      body = "Email already exists";
    } else {
      console.error(e);
      body = "Unexpected error";
    }
    return {
      statusCode: 500,
      body,
    };
  }

  return {
    statusCode: 200,
    headers: {
      "Access-Control-Allow-Origin": "*",
      "Access-Control-Allow-Headers":
        "Origin, X-Requested-With, Content-Type, Accept",
      "Access-Control-Allow-Methods": "POST, OPTIONS",
      "Access-Control-Max-Age": "2592000",
      "Access-Control-Allow-Credentials": "true",
    },
  };
};
