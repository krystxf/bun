var i=function(N){var m=g({basename:N.basename.bind(N),dirname:N.dirname.bind(N),extname:N.extname.bind(N),format:N.format.bind(N),isAbsolute:N.isAbsolute.bind(N),join:N.join.bind(N),normalize:N.normalize.bind(N),parse:N.parse.bind(N),relative:N.relative.bind(N),resolve:N.resolve.bind(N),toNamespacedPath:N.toNamespacedPath.bind(N),sep:N.sep,delimiter:N.delimiter});return m.default=m,m},g=(N)=>Object.assign(Object.create(null),N),f=i(Bun._Path()),J=i(Bun._Path(!1)),k=i(Bun._Path(!0));f.win32=k;f.posix=J;var{basename:q,dirname:v,extname:y,format:z,isAbsolute:A,join:B,normalize:K,parse:C,relative:D,resolve:E,toNamespacedPath:F,sep:G,delimiter:H,__esModule:I}=f;f[Symbol.for("CommonJS")]=0;f.__esModule=!0;var O=f;export{k as win32,F as toNamespacedPath,G as sep,E as resolve,D as relative,J as posix,C as parse,K as normalize,B as join,A as isAbsolute,z as format,y as extname,v as dirname,H as delimiter,O as default,g as createModule,q as basename,I as __esModule};
