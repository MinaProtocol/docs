"use strict";

const qs = require("querystring");
const axios = require("axios");

let HUBSPOT_FORM_URL =
  "https://api.hsforms.com/submissions/v3/integration/submit";

const { PORTALID, FORMID } = process.env;

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
  const payload = { fields: [{ name: "email", value: data.email }] };

  try {
    await axios.post(`${HUBSPOT_FORM_URL}/${PORTALID}/${FORMID}`, payload, {
      headers: {
        "Content-Type": "application/json",
      },
    });
  } catch (e) {
    console.error(e);
    return {
      statusCode: 500,
      body: "",
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
