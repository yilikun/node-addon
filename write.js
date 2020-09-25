const fs = require("fs");

fs.writeFileSync(`./.gitignore`, "*.temp\n*.mrpa");